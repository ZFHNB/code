#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>

/* 
socket
bind
listen
accept 
write
read
*/

#define SERVER_PORT 8888
#define BACKLOG 10
#define BUFSIZE 1000

int main(int argc, char **argv)
{
    /* 服务端和客户端的套接字文件描述符 */
    int iSocketServer;
    int iSocketClient;
    /* 地址信息，在之后针对结构体内各项进行设置 */
    struct sockaddr_in tSocketServerAddr;//服务器端的地址信息
    struct sockaddr_in tSocketClientAddr;//客户端的地址信息
    int iRet;//获取函数调用返回值
    int iAddrLen;//地址长度，随用随赋值

    ssize_t iRecvLen;//接收数据的bytes数
    unsigned char recvBuf[BUFSIZE + 1];//接收缓冲区

    int iClientNum = -1;//标识不同客户端

    iSocketServer = socket(AF_INET, SOCK_STREAM, 0);//(IPv4网络协议, TCP, 协议),不包含IP、端口信息

    if(-1 == iSocketServer)
    {
        printf("socket error!\n");
        return -1;
    }

    tSocketServerAddr.sin_family = AF_INET;//IPv4网络协议
    tSocketServerAddr.sin_port = htons(SERVER_PORT);//host to net short-->把主机字节序转化为网络字节序
    tSocketServerAddr.sin_addr.s_addr = INADDR_ANY;//将服务器的IP地址设置为“任意”，服务器将监听所有可用的网络接口上的指定端口
    memset(tSocketServerAddr.sin_zero, 0, 8);

    /* 绑定IP、端口信息到句柄 */
    iRet = bind(iSocketServer, (const struct sockaddr *)&tSocketServerAddr, sizeof(struct sockaddr));
    if(-1 == iRet)
    {
        printf("bind error\n");
        return -1;
    }

    iRet = listen(iSocketServer, BACKLOG);//backlog-->同时监听多少路连接
    if(-1 == iRet)
    {
        printf("listen error\n");
        return -1;
    }

    while(1)
    {
        iAddrLen = sizeof(struct sockaddr);
        iSocketClient = accept(iSocketServer, (struct sockaddr *)&tSocketClientAddr, &iAddrLen);
        if(-1 != iSocketClient)//客户端连接成功
        {
            iClientNum ++;
            printf("Gen connect form Client %d : %s\n", iClientNum, inet_ntoa(tSocketClientAddr.sin_addr));
            /* 对每一个连接都创建一个子进程 */
            if(!fork())//复制出子进程，运行if分支，父进程运行else分支
            {
                /* 子进程源码 */
                while(1)
                {
                    /* 接收客户端发来的数据，并显示出来 */
                    iRecvLen = read(iSocketClient, recvBuf, BUFSIZE);//(源，目的，大小)
                    if(iRecvLen <= 0)
                    {
                        close(iSocketClient);
                        return -1;
                    }
                    else
                    {
                        recvBuf[iRecvLen] = '\0';//追加字符串结束标识符
                        /* 打印客户端消息 */
                        printf("Get Msg From Client %d :\n", iClientNum);
                        printf("> %s\n", recvBuf);
                    }
                }

            }
        }
    }
    close(iSocketServer);
    return 0;
}