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
* argc = ...
* argv[0] = ./write
* argv[1] = 1.txt
*/

int main(int argc, char** argv)
{
    int fd;
    int i;
    int len;

    if(argc < 3)
    {
        printf("Usage: %s <file> <string 1> <string 2> ...\n", argv[0]);//<>表示参数不可省略
        exit(1);
    }

    fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0777);//int open(const char *pathname, int flags, mode_t mode)
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

    //顺序写入数据
    for(i = 2; i < argc; i++)
    {
        len = write(fd, argv[i], strlen(argv[i]));
        if(len != strlen(argv[i]))
        {
            perror("write");
            break;
        }
        write(fd, "\r\n", 2);
    }

    close(fd);
    return 0;
}