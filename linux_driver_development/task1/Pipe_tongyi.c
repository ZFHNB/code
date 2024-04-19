#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 100
#define NUM_MESSAGES 5

// 函数：处理错误信息并退出程序
void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int pipefd[2]; // 管道文件描述符
    pid_t pid;     // 子进程ID
    char buffer[BUFFER_SIZE]; // 用于存储消息字符串的缓冲区
    int bytes_read;

    // 步骤1：创建用于父进程与子进程间通信的管道
    if (pipe(pipefd) == -1) {
        handle_error("pipe");
    }

    // 步骤2：通过 fork 创建子进程
    pid = fork();
    if (pid == -1) {
        handle_error("fork");
    }

    if (pid == 0) { // 子进程
        close(pipefd[0]); // 在子进程中关闭管道读端

        // 步骤2继续：子进程循环输出 "I am child." 并将其发送给父进程
        for (int i = 0; i < NUM_MESSAGES; ++i) {
            printf("I am child.\n");
            fflush(stdout); // 确保立即输出到控制台
            sleep(1);

            // 通过管道将字符串发送给父进程
            const char *child_msg = "I am child.";
            write(pipefd[1], child_msg, strlen(child_msg) + 1);
        }

        close(pipefd[1]); // 在子进程中关闭管道写端
        exit(EXIT_SUCCESS);
    } else { // 父进程
        close(pipefd[1]); // 在父进程中关闭管道写端

        // 步骤3：父进程循环输出 "I am parent." 并从子进程接收数据
        for (int i = 0; i < NUM_MESSAGES; ++i) {
            printf("I am parent.\n");
            fflush(stdout); // 确保立即输出到控制台
            sleep(1);

            // 通过管道从子进程读取消息
            bytes_read = read(pipefd[0], buffer, BUFFER_SIZE - 1);
            if (bytes_read == -1) {
                handle_error("read");
            }
            buffer[bytes_read] = '\0'; // 对接收到的字符串进行空字符终止

            printf("Received from child: %s\n", buffer);
        }

        close(pipefd[0]); // 在父进程中关闭管道读端

        // 步骤5：等待子进程结束
        wait(NULL);
    }

    return 0;
}