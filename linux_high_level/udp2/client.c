#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>

/* socket
 * connect(可以不使用，若不使用，则需要使用sendto/recvfrom（这两个函数内可以绑定地址信息），
                      若使用，则可以使用read、write函数)
 * sendto/recvfrom
 */

#define SERVER_PORT 8888
#define BUFSIZE 1000

int main(int argc, char **argv)
{
    int iSocketClient;
    struct sockaddr_in tSocketServerAddr;

    int iRet;
    unsigned char sendBuf[BUFSIZE + 1];
    ssize_t iSendLen;
    int iAddrLen;

    if(argc != 2)
    {
        printf("Usage:\n");
        printf("%s <server_ip>\n", argv[0]);
        return -1;
    }

    iSocketClient = socket(AF_INET, SOCK_DGRAM, 0);//(IPv4网络协议, TCP, 协议),不包含IP、端口信息

    tSocketServerAddr.sin_family = AF_INET;//IPv4
    tSocketServerAddr.sin_port = htons(SERVER_PORT);//host to net-->把主机字节序转化为网络字节序
    //tSocketServerAddr.sin_addr.s_addr = INADDR_ANY;
    if(0 == inet_aton(argv[1], &tSocketServerAddr.sin_addr))//将传入的服务端IP地址（点分十进制）转换为二进制形式，存储在tSocketServerAddr.sin_addr中
    {
        printf("invalid server_ip\n");
        return -1;
    }
    memset(tSocketServerAddr.sin_zero, 0, 8);

    //不使用connect函数
    /* (客户端套接字句柄，服务器IP地址，地址大小) */
    /* iRet = connect(iSocketClient, (const struct sockaddr *)&tSocketServerAddr, sizeof(struct sockaddr));
    if(-1 == iRet)
    {
        printf("connec error\n");
        return -1;
    } */

    while(1)
    {
        printf("> ");
        if(NULL != fgets(sendBuf, BUFSIZE, stdin))//从标准输入获取数据，存入缓冲区
        {
#if 0
            iSendLen = write(iSocketClient,sendBuf,strlen(sendBuf));
#else
            /* 使用sendto函数发信息 */
            iAddrLen = sizeof(struct sockaddr);
            iSendLen = sendto(iSocketClient, sendBuf, strlen(sendBuf), 0, (const struct sockaddr *)&tSocketServerAddr, iAddrLen);
#endif
            if(iSendLen <= 0)
            {
                close(iSocketClient);
                return -1;
            }
        }
    }

    return 0;
}