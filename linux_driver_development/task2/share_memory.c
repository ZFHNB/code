#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <sys/types.h>  
#include <unistd.h>  
#include <sys/ipc.h>  
#include <sys/shm.h>  
#include <sys/wait.h>  
  
/* 定义最大子进程数 */
#define MAX_CHILDREN 3  
/* 定义循环计数 */
#define LOOP_COUNT 5  
/* 定义共享内存大小 */
#define SHM_SIZE 1024  
  
int main() {  
    int shmid;  
    char *shm_addr;  
    pid_t pid[MAX_CHILDREN];  
    int status;  
  
    // 创建一个私有的共享内存  
    if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666)) < 0) {  
        perror("shmget");  
        exit(1);  
    }  
  
  
    /* 将共享内存附加到进程的地址空间 */
    if ((shm_addr = (char *)shmat(shmid, NULL, 0)) == (char *)-1) {  
        perror("shmat");  
        exit(1);  
    }  
  
    // 创建子进程  
    for (int i = 0; i < MAX_CHILDREN; i++) {  
        pid[i] = fork();  
        if (pid[i] < 0) {  
            perror("fork");  
            exit(1);  
        } else if (pid[i] == 0) { // 子进程  
            for (int j = 0; j < LOOP_COUNT; j++) {  
                printf("Child(%d): loops(%d)\n", i + 1, j);  
                sleep(1);  
            }  
            exit(0);  
        }  
    }  
  
    // 等待所有子进程结束  
    for (int i = 0; i < MAX_CHILDREN; i++) {  
        waitpid(pid[i], &status, 0);  
    }  
  
    // 父进程分离并删除共享内存  
    shmdt(shm_addr);  
    shmctl(shmid, IPC_RMID, NULL);  
  
    return 0;  
}