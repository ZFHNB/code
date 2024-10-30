#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO1 "in1"
#define FIFO2 "in2"
#define MAX_BUFFER_SIZE 1024
#define IN_FILES 3
#define TIME_DELAY 60
#define MAX(a, b) ((a > b) ? (a) : (b))

int main()
{
    int fds[IN_FILES];
    char buf[MAX_BUFFER_SIZE];
    int i, res, real_read, maxfd;
    struct timeval tv;
    fd_set inset, tmp_inset;
    fds[0] = 0;

    /*创建两个有名管道*/
    if(access(FIFO1, F_OK) == -1) //确定文件可被访问
    {
        if((mkfifo(FIFO1, 0666) < 0) && (errno != EEXIST))
        {
            perror("creat fifo file");
            exit(1);
        }
    }
     if(access(FIFO2, F_OK) == -1) //确定文件可被访问
    {
        if((mkfifo(FIFO2, 0666) < 0) && (errno != EEXIST))
        {
            perror("creat fifo file");
            exit(1);
        }
    }

    //以只读非阻塞方式阿凯两个管道文件
    if((fds[1] = open (FIFO1, O_RDONLY|O_NONBLOCK)) < 0)
    {
        perror("open in1");
        exit(1);
    }
    if((fds[2] = open (FIFO2, O_RDONLY|O_NONBLOCK)) < 0)
    {
        perror("open in2");
        exit(1);
    }

    /*取出两个文件描述符中的较大者*/
    maxfd = MAX(MAX(fds[0], fds[1]), fds[2]);
    /*初始化读集inset，并在读文件描述符集中加入相应的描述集*/
    FD_ZERO(&inset);
    for(i = 0; i < IN_FILES; i++)
    {
        FD_SET(fds[i], &inset);//将文件描述符放入集
    }
    FD_SET(0, &inset);

    tv.tv_sec = TIME_DELAY;
    tv.tv_usec = 0;
    /*循环测试该文件描述符是否准备就绪，并调用select()函数对相关文件描述符做相应操作*/
    while (FD_ISSET(fds[0], &inset) || FD_ISSET(fds[1], &inset) || FD_ISSET(fds[2], &inset))
    {
        /*文件描述符集备份*/
        tmp_inset = inset;
        res = select(maxfd + 1, &tmp_inset, NULL, NULL, &tv);
        switch(res)
        {
            case -1:
            {
                perror("select");
                exit(1);
            }
            break;
            case 0:/*超时*/
            {
                printf("超时");
                exit(1);
            }
            break;
            default:
            {
                for(int i = 0; i < IN_FILES; i++)
                {
                    if(FD_ISSET(fds[i], &tmp_inset))
                    {
                        memset(buf, 0, MAX_BUFFER_SIZE);//创建共享内存
                        real_read = read(fds[i], buf, MAX_BUFFER_SIZE);
                        if(real_read < 0)
                        {
                            if(errno != EAGAIN)//EAGAIN资源暂时不可用
                            {
                                exit(1);
                            }
                        }
                        else if(!real_read)
                        {
                            close(fds[i]);
                            FD_CLR(fds[i], &inset);
                        }
                        else
                        {
                            if(i == 0)//主程序终端控制
                            {
                                if((buf[0] == 'q') || (buf[0] == 'Q'))
                                {
                                    exit(1);
                                }
                            }
                            else//显示管道输入字符串
                            {
                                buf[real_read] = '\0';
                                printf("%s", buf);
                            }
                        }
                    }
                }
            }
            break;
        }
    }
    return 0;
}