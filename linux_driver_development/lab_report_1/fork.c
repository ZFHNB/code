#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <sys/wait.h>  
  
int main() {  
    pid_t child1, child2, child;  
    int status;  
  
    // 创建第一个子进程来执行 "ls -l" 命令  
    child1 = fork();  
    if (child1 == 0) {  
        // 子进程1  
        execlp("ls", "ls", "-l", (char *)NULL);  
        perror("execlp");  
        exit(1);  
    } else if (child1 < 0) {  
        perror("fork1");  
        exit(1);  
    }  
  
    // 创建第二个子进程，该子进程将在5秒后异常退出  
    child2 = fork();  
    if (child2 == 0) {  
        // 子进程2  
        printf("在子进程2中，暂停5s后退出\n");
        sleep(5); // 暂停5秒  
        // 异常退出   
        exit(1);  
    } else if (child2 < 0) {  
        perror("fork2");  
        exit(1);  
    }  
    else
    {
        //父进程
        printf("现在是父进程\n");
        // 阻塞式等待子进程1结束  
        child = waitpid(child1, NULL, 0);  
        if(child == child1)
        {
            printf("获取到子进程1的退出码\n");
        }
        else
        {
            printf("子进程1退出码获取失败\n");
        }

         do
        {
            //采用循环加非阻塞等待的方式检查子进程2是否退出  
            child = waitpid(child2, NULL, WNOHANG);  
            if(child == 0)
            {
                printf("子进程2还未退出\n");
                sleep(1);
            }
        } while (child == 0);
        
        if(child == child2)
        {
            printf("获取到子进程2退出码\n");
        }
        else
        {
            printf("子进程1退出码获取失败\n");
        }
    }
  
    return 0;  
}