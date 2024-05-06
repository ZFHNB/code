#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <asm-generic/socket.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 100

void remove_newline(char *str) {
    int len = strlen(str);
    if (str[len - 1] == '\n') str[len - 1] = '\0';
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER_SIZE] = {0};
    
    // 创建套接字
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // 设置套接字选项，允许重复使用地址
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // 绑定套接字到地址
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // 监听连接请求
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    while(1) {
        printf("Waiting for a connection...\n");
        
        // 接受客户端连接
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        printf("Connection accepted\n");
        
        // 接收客户端消息
        while((valread = read(new_socket, buffer, MAX_BUFFER_SIZE)) > 0) {
            remove_newline(buffer); // 移除换行符
            printf("Client: %s\n", buffer);
            
            if(strcmp(buffer, "exit") == 0) {
                printf("Server is exiting...\n");
                break;
            }
            
            // 反馈给客户端（可选）
            write(new_socket, "服务器收到消息", strlen("服务器收到消息"));
        }
        
        if(valread == 0) {
            printf("Client disconnected\n");
        } else if(valread == -1) {
            perror("read");
        }
        
        close(new_socket); // 关闭连接
    }
    
    return 0;
}