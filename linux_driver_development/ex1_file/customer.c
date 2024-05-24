#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_FILE_SIZE 10*1024*1024

const char *fifo_file = "./myfifo";
const char *temp_file = "./temp";

int lock_set(int fd, int type)//初始化锁
{
    struct flock old_lock, lock;
    {
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len = 0;
        lock.l_type = type;
        lock.l_pid = -1;
    }

    fcntl(fd, F_GETLK, &lock);
    if(lock.l_type != F_UNLCK)
    {
        if(lock.l_type == F_RDLCK)
        {
            perror("读锁");
        }
        if(lock.l_type == F_WRLCK)
        {
            perror("写锁");
        }
    }

    lock.l_type = type;
    if(fcntl(fd, F_SETLK, &lock) < 0)
    {
        perror("上锁失败");
        return -1;
    }
    return 0;
}
int fileCopy(const char *source, const char *dest, int offset, int counter)
{
    int s_file, d_file;
    char buff;

    if ((s_file = open(source, O_RDONLY | O_NONBLOCK)) < 0)
    {
        perror("源文件打开错误");
        return -1;
    }
    if ((d_file = open(dest, O_RDWR | O_CREAT | O_TRUNC | O_NONBLOCK, 0644)) < 0)
    {
        perror("目标文件打开错误");
        close(s_file);
        return -1;
    }

    lseek(s_file, offset, SEEK_SET);
    while ((read(s_file, &buff, 1)) == 1)
    {
        write(d_file, &buff, 1);
        counter++;
    }

    close(s_file);
    close(d_file);
    return 0;
}

int customing(const char *fifo)
{
    int fd;
    char buff;
    int counter = 0;
    int need;

    fd = open(fifo, O_RDONLY);
    if (fd < 0)
    {
        perror("打开FIFO文件失败");
        return -1;
    }

    printf("需要移除的数据量： ");
    scanf("%d", &need);

    lseek(fd, SEEK_SET, 0);

    // 使用一个临时变量保存read的结果，避免在while条件中调用read
    ssize_t bytesRead;
    while ((bytesRead = read(fd, &buff, 1)) == 1 && counter < need)
    {
        fputc(buff, stdout);
        counter++;
    }

    // 检查read是否遇到文件结束或错误
    if (bytesRead == 0)
    {
        printf("已到达文件末尾\n");
    }
    else if (bytesRead == -1)
    {
        perror("读取FIFO文件时出错");
    }

    close(fd);
    return 0;
}

int custom(int need)
{
    int fd;

    customing(fifo_file);

    if ((fd = open(fifo_file, O_RDWR)) < 0)
    {
        perror("自定义读取失败");
        return -1;
    }

    // 复制数据
    lock_set(fd, F_WRLCK);
    fileCopy(fifo_file, temp_file, need, need); // 将源文件内容（偏移后）拷贝到临时文件中
    fileCopy(temp_file, fifo_file, 0, MAX_FILE_SIZE); // 将偏移后的文件内容拷贝回来

    lock_set(fd, F_UNLCK);
    unlink(temp_file); // 删除临时文件
    close(fd);
}

int main(int argc, char **argv)
{
    int customer_size = 1;
    if (argc > 1)
    {
        sscanf(argv[1], "%d", &customer_size);
    }
    if (customer_size > 0)
    {
        custom(customer_size);
    }

    return 0;
}