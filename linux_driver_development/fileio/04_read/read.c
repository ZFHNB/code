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
* ./read 1.txt
* argc = 0
* argv[0] = ./read
* argv[1] = 1.txt
*/

int main(int argc, char** argv)
{
    int fd;
    int i;
    int len;
    unsigned char buf[100];

    if(argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);//<>表示参数不可省略
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);//int open(const char *pathname, int flags, mode_t mode)
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

    /* 读文件/打印 */
    while(1)
    {
        len = read(fd, buf, sizeof(buf)-1);
        if(len < 0)//读取错误返回值wei-1
        {
            perror("read");
            close(fd);
            exit(1);
        }
        else if(len == 0)//表示读到文件尾部
        {
            break;
        }
        else
        {
            /* buf[0], buf[1], ..., buf[len-1] 含有读出的数据
            *  buf[len] = '\0'
            */
        buf[len] = '\0';
        printf("%s", buf);
        }
    }

    close(fd);
    return 0;
}