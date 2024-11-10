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
sendto/recvfrom
*/

#define SERVER_PORT 8888
#define BACKLOG 10
#define BUFSIZE 1000

int main(int argc, char **argv)
{
    /* 服务端的套接字文件描述符 */
    int iSocketServer;
    /* 地址信息，在之后针对结构体内各项进行设置 */
    struct sockaddr_in tSocketServerAddr;//服务器端的地址信息
    struct sockaddr_in tSocketClientAddr;//客户端的地址信息
    int iRet;
    int iAddrLen;//地址长度，随用随赋值

    ssize_t iRecvLen;//接收数据的bytes数
    unsigned char recvBuf[BUFSIZE + 1];//接收缓冲区

    int iClientNum = -1;//标识不同客户端

    iSocketServer = socket(AF_INET, SOCK_DGRAM, 0);//(IPv4网络协议, UDP, 协议),不包含IP、端口信息

    if(-1 == iSocketServer)
    {
        printf("socket error!\n");
        return -1;
    }

    tSocketServerAddr.sin_family = AF_INET;//IPv4网络协议
    tSocketServerAddr.sin_port = htons(SERVER_PORT);//host to net-->把主机字节序转化为网络字节序
    tSocketServerAddr.sin_addr.s_addr = INADDR_ANY;//将服务器的IP地址设置为“任意”，服务器将监听所有可用的网络接口上的指定端口
    memset(tSocketServerAddr.sin_zero, 0, 8);

    /* 绑定IP、端口信息到句柄 */
    iRet = bind(iSocketServer, (const struct sockaddr *)&tSocketServerAddr, sizeof(struct sockaddr));
    if(-1 == iRet)
    {
        printf("bind error\n");
        return -1;
    }

    while(1)
    {
        iAddrLen = sizeof(struct sockaddr);
        iRecvLen = recvfrom(iSocketServer, &recvBuf, BUFSIZE, 0, (struct sockaddr *)&tSocketClientAddr, &iAddrLen);
        if(iRecvLen > 0)
        {
            recvBuf[iRecvLen] = '\0';
            printf("Get Message from %s :\n", inet_ntoa(tSocketClientAddr.sin_addr));
            printf("> %s\n", recvBuf);
        }
    }
    close(iSocketServer);
    return 0;
}