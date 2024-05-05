// 可以使用man man open查看帮助信息
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);//<>表示参数不可省略
        exit(1);
    }

    int fd = open(argv[1],O_RDONLY);

    printf("fd = %d", fd);

    while(1)
    {
        sleep(100);
    }

    return 0;
}