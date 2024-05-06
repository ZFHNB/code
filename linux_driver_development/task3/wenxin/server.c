#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <arpa/inet.h>  
#include <sys/socket.h>  
  
#define BUF_SIZE 1024  
  
void remove_newline(char *str) {  
    size_t len = strlen(str);  
    if (len > 0 && str[len - 1] == '\n') {  
        str[len - 1] = '\0';  
    }  
}  
  
int main() {  
    int server_fd, client_fd;  
    struct sockaddr_in server_addr, client_addr;  
    char buffer[BUF_SIZE];  
    socklen_t client_len = sizeof(client_addr);  
  
    server_fd = socket(AF_INET, SOCK_STREAM, 0);  
    memset(&server_addr, 0, sizeof(server_addr));  
    server_addr.sin_family = AF_INET;  
    server_addr.sin_addr.s_addr = INADDR_ANY;  
  
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {  
        perror("Bind failed");  
        exit(1);  
    }  
  
    listen(server_fd, 5);   
  
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);  
    printf("Client connected.\n");  
  
    while (1) {  
        memset(buffer, 0, BUF_SIZE);  
        if (recv(client_fd, buffer, BUF_SIZE, 0) <= 0) {  
            break;  
        }  
        remove_newline(buffer);  
        if (strcmp(buffer, "exit") == 0) {  
            break;  
        }  

    // Echo the message back to the client  
        send(client_fd, buffer, strlen(buffer), 0);  
  
        if (strcmp(buffer, "exit") == 0) {  
            break;  
        }  

        printf("Received from client: %s\n", buffer);  
    }  
  
    close(client_fd);  
    close(server_fd);  
    return 0;  
}