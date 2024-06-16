#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>

// 移除字符串末尾的换行符
void remove_newline(char *str) {
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
#define PORT 12345

// 客户端
#define PORT 12345

// 客户端
int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[1024] = {0};

    // 创建套接字文件描述符
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    // 设置服务器地址
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // 连接到服务器
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    printf("Connected to the server\n");

    // 持续发送和接收消息
    while (1) {
        printf("Enter message : ");
        fgets(buffer, 1024, stdin);
        remove_newline(buffer);

        // 发送消息
        write(sock, buffer, strlen(buffer));
        
        // 接收消息
        int valread = read(sock, buffer, 1024);
        if (valread <= 0) {
            perror("read");
            break; // 服务器端断开连接
        }
        buffer[valread] = '\0'; // 确保字符串正确终止
        remove_newline(buffer);
        printf("Server : %s\n", buffer);

        if (strcmp(buffer, "exit") == 0) {
            printf("Server disconnected.\n");
            break;
        }
    }

    close(sock);
    return 0;
}