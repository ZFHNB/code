#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>

/* socket
 * connect
 * write/read
 */

#define SERVER_PORT 8888
#define BUFSIZE 1000

int main(int argc, char **argv)
{
    int iSocketClient;//客户端套接字文件描述符
    struct sockaddr_in tSocketServerAddr;//客户端地址信息，IP由用户手动输入

    int iRet;//获取函数返回值
    unsigned char sendBuf[BUFSIZE + 1];//发送缓冲
    ssize_t iSendLen;//发送bytes数

    /* 用户输入判断，需要用户手动输入IP */
    if(argc != 2)
    {
        printf("Usage:\n");
        printf("%s <server_ip>\n", argv[0]);
        return -1;
    }

    iSocketClient = socket(AF_INET, SOCK_STREAM, 0);//(IPv4网络协议, TCP, 协议),不包含IP、端口信息

    tSocketServerAddr.sin_family = AF_INET;
    tSocketServerAddr.sin_port = htons(SERVER_PORT);//host to net-->把主机字节序转化为网络字节序
    //tSocketServerAddr.sin_addr.s_addr = INADDR_ANY;
    if(0 == inet_aton(argv[1], &tSocketServerAddr.sin_addr))//将传入的服务端IP地址（点分十进制）转换为二进制形式，存储在tSocketServerAddr.sin_addr中
    {
        printf("invalid server_ip\n");
        return -1;
    }
    memset(tSocketServerAddr.sin_zero, 0, 8);

    /* (客户端套接字句柄，服务器IP地址，地址大小) */
    iRet = connect(iSocketClient, (const struct sockaddr *)&tSocketServerAddr, sizeof(struct sockaddr));
    if(-1 == iRet)
    {
        printf("connec error\n");
        return -1;
    }

    while(1)
    {
        printf("> ");
        if(NULL != fgets(sendBuf, BUFSIZE, stdin))//从标准输入获取数据，存入缓冲区
        {
            iSendLen = write(iSocketClient,sendBuf,strlen(sendBuf));
            if(iSendLen <= 0)
            {
                close(iSocketClient);
                return -1;
            }
        }
    }

    return 0;
}