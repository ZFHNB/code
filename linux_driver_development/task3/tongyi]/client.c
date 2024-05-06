#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

void remove_newline(char *str) {
    int len = strlen(str);
    if (str[len - 1] == '\n') str[len - 1] = '\0';
}

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *message, buffer[MAX_BUFFER_SIZE] = {0};
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    
    printf("Connected to the server.\n");
    
    while(1) {
        printf("> ");
        fgets(message, MAX_BUFFER_SIZE, stdin);
        remove_newline(message);
        
        if(strcmp(message, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }
        
        send(sock, message, strlen(message), 0);
        valread = read(sock, buffer, MAX_BUFFER_SIZE);
        
        if(valread > 0) {
            remove_newline(buffer);
            printf("Server: %s\n", buffer);
                if(strcmp(buffer, "exit") == 0) {
                printf("Received 'exit' from server, quitting...\n");
                break; // 退出循环，客户端将退出
            }
        }
    }
    
    close(sock);
    return 0;
}