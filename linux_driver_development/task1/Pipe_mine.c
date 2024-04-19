// 编写一个 C 程序，实现以下功能：
//  1.创建一个管道，用于父子进程之间的通信。
//  2.创建一个子进程，子进程在自己的循环中输出字符串 "I am child."，
//  每次输出后程序使用 sleep(1) 延时1秒，共输出5次。
//  3.父进程在自己的循环中输出字符串 "I am parent."，
//  每次输出后程序使用 sleep(1) 延时1秒，共输出5次。
//  4.子进程将输出的字符串发送给父进程，
//  父进程接收并打印子进程发送的字符串。
//  5.程序结束时正确关闭管道
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 100

int main()
{
    int pipefd[2];//管道文件描述符（fd[0]读端，fd[1]写端）
    pid_t pid;//子进程pid
    char buffer[BUFFER_SIZE];//存储消息字符串
    int real_read;

    //1.创建父子进程之间通信的管道
    if(pipe(pipefd) == -1)
    {
        printf("管道创建失败\n");
        exit(1);
    }

    //2.创建子进程
    if((pid = fork()) == -1)
    {
        printf("子进程创建失败\n");
        exit(1);
    }
    else if(pid == 0)//子进程
    {
        close(pipefd[0]);//关闭读端->子进程写

        for(int i = 0; i < 5; i++)
        {
            const char *cmsg = "I am child.";
            printf("%s\n",cmsg);
            sleep(1);

            //将子进程输出的字符串发送给父进程
            if(write(pipefd[1], cmsg, strlen(cmsg)+1) == -1)
            {
                printf("子进程写入错误\n");
                exit(1);
            }
        }

        close(pipefd[1]);//关闭写端
        exit(0);
    }
    else//3.父进程
    {
        close(pipefd[1]);//关闭写端

        for(int i = 0; i < 5; i++)
        {
            const char *pmsg = "I am parent.";
            printf("%s\n",pmsg);
            sleep(1);

           // 从管道中读取子进程发送的信息
            if ((real_read = read(pipefd[0], buffer, BUFFER_SIZE - 1)) == -1)
            {
                printf("父进程读取错误: %s\n", strerror(errno));
            }
            buffer[real_read] = '\0'; 
            printf("从子进程中传来的信息为：%s\n", buffer);
        }

        close(pipefd[0]); // 关闭读端

        // 等待子进程结束
        wait(NULL);
    }

    return 0;
}