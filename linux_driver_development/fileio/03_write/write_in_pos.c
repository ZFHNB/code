//可以使用man man open查看帮助信息
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/*
* ./write 1.txt str1 str2
* argc = 0
* argv[0] = ./write
* argv[1] = 1.txt
*/

int main(int argc, char** argv)
{
    int fd;
    int i;
    int len;

    if(argc !=2)
    {
        printf("Usage: %s <file>\n", argv[0]);//<>表示参数不可省略
        exit(1);
    }

    fd = open(argv[1], O_RDWR | O_CREAT, 0777);//int open(const char *pathname, int flags, mode_t mode)
    if(fd < 0)
    {
        printf("Can not open file %s\n", argv[1]);
        printf("errno = %d\n",errno);
        printf("err: %s\n", strerror(errno));
        perror("open");
    }
    else
    {
        printf("fd = %d\n",fd);
    }

    //插入数据（会覆盖原有数据）
    lseek(fd, 3, SEEK_SET);
    write(fd, "222", 3);

    close(fd);
    return 0;
}