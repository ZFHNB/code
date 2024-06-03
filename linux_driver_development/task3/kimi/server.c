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

// 服务器端
int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[1024] = {0};

    // 创建套接字文件描述符
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // 绑定套接字到端口
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // 监听端口
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // 接受客户端连接
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
    if (client_fd < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // 持续接收客户端消息
    while (1) {
        // 接收消息
        int valread = read(client_fd, buffer, 1024);
        if (valread <= 0) {
            perror("Client disconnected");
            break; // 客户端断开连接
        }
        buffer[valread] = '\0'; // 确保字符串正确终止
        remove_newline(buffer);
        printf("Message from client: %s\n", buffer);

        // 检查是否接收到退出命令
        if (strcmp(buffer, "exit") == 0) {
            printf("Client requested to exit.\n");
            write(client_fd, "exit", 4); // 发送退出命令给客户端
            break; // 退出循环
        }

        // 打印提示信息并接收服务器端用户的输入
        printf("Enter message (or 'exit' to quit): ");
        fgets(buffer, 1024, stdin);
        remove_newline(buffer);

        // 发送消息到客户端
        write(client_fd, buffer, strlen(buffer));

        // 检查服务器端用户是否输入退出命令
        if (strcmp(buffer, "exit") == 0) {
            printf("Server is exiting...\n");
            break; // 退出循环
        }
    }

    // 关闭连接
    close(client_fd);
    close(server_fd);
    return 0;
}