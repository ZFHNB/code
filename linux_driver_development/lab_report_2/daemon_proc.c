#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <syslog.h>
#include <sys/stat.h>

int main()
{
    pid_t child1, child2;
    int i;

    /* 创建子进程1 */
    child1 = fork();
    if(child1 == -1)
    {
        perror("child1 fork");
        exit(1);
    }
    else if(child1 > 0)
    {
        exit(0);//父进程退出
    }

    openlog("daemon_proc_info",LOG_PID, LOG_DAEMON);

    /* 编写守护进程 */
    setsid();
    chdir("/");
    umask(0);
    for(i = 0; i < getdtablesize(); i++)
        close(i);

    /* 创建子进程2 */
    child2 = fork();
    if(child2 == -1)
    {
        perror("child2 fork");
        exit(1);
    }
    else if(child2 == 0)//子进程2
    {
        //在日志中写入字符串
        syslog(LOG_INFO, "child2 will sleep for 10s");
        sleep(10);
        syslog(LOG_INFO, "child2 is going to exit!");
        exit(0);
    }
    else//子进程1
    {
        waitpid(child2, NULL, 0);
        syslog(LOG_INFO, " child1 noticed that child2 has exited ");
        //关闭日志服务
        closelog();
        while(1)
        {
            sleep(10);
        }
    }

    return 0;
}