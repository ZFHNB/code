#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define PORT 8080
#define SERVER_IP "127.0.0.1"

void remove_newline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

int main()
{
    int sock_fd;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Connect failed");
        exit(1);
    }
    printf("Connected to server.\n");

    while (1)
    {
        printf("> ");
        fgets(buffer, BUF_SIZE, stdin);
        remove_newline(buffer);
        if (strcmp(buffer, "exit") == 0)
        {
            break;
        }
        send(sock_fd, buffer, strlen(buffer), 0);
    }

    // 客户端代码中，在发送消息循环之后或另一个线程中添加
    while (1)
    {
        memset(buffer, 0, BUF_SIZE);
        int bytes_received = recv(sock_fd, buffer, BUF_SIZE, 0);
        if (bytes_received <= 0)
        {
            break;
        }
        buffer[bytes_received] = '\0'; // 确保字符串正确终止
        remove_newline(buffer);
        if (strcmp(buffer, "exit") == 0)
        {
            break;
        }
        printf("Received from server: %s\n", buffer);
    }

    close(sock_fd);
    return 0;
}