#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 25

int main() {
    int fd[2]; // 文件描述符数组，fd[0]用于读，fd[1]用于写
    pid_t pid;
    char buffer[BUFFER_SIZE];

    // 创建管道
    if (pipe(fd) < 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // 创建子进程
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // 子进程
        close(fd[0]); // 关闭读端

        for (int i = 0; i < 5; i++) {
            sleep(1);
            write(fd[1], "I am child.\n", strlen("I am child.\n"));
        }

        close(fd[1]); // 写完数据后关闭写端
        exit(EXIT_SUCCESS);
    } else { // 父进程
        close(fd[1]); // 关闭写端

        for (int i = 0; i < 5; i++) {
            read(fd[0], buffer, BUFFER_SIZE);
            printf("Parent received: %s", buffer);
            sleep(1);
        }

        close(fd[0]); // 读完数据后关闭读端
    }

    return 0;
}
