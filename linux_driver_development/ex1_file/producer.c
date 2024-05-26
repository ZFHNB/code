#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define MAX_LEN 10
#define fifo_file "./myfifo"

char buff[MAX_LEN];

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

int product(void)//生产产品
{
    int fd;
    unsigned int size;
    static unsigned int counter = 0;

    fd = open(fifo_file, O_CREAT | O_RDWR | O_APPEND, 0664);
    if(fd < 0)
    {
        perror("open");
        exit(1);
    }

    sprintf(buff, "%c", ('a' + counter));
    counter = (counter + 1) % 26;

    //lock file
    lock_set(fd, F_WRLCK);//上写锁
    if((size = write(fd, buff, strlen(buff)) < 0))
    {
        perror("write");
        return -1;
    }

    lock_set(fd, F_UNLCK);
    close(fd);

    return 0;
}

int main(int argc, char **argv)
{
    int time_step = 1;
    int time_life = 10;

    if(argc > 1)
    {
        sscanf(argv[1], "%d", &time_step);
    }
    if(argc > 2)
    {
        sscanf(argv[2], "%d", &time_life);
    }

    while(time_life --)
    {
        if(product() < 0)
        {
            perror("product");
            break;
        }
        sleep(time_step);
    }

    return 0;
}