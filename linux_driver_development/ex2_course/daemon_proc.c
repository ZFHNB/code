#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    pid_t child1, child2;

    child1 = fork();//第一步
    if(child1 == -1)
    {
        perror("child1 fork");
        exit(1);
    }
    else if(child1 > 1)
    {
        exit(0); //father process killed
    }
    openlog("daemon_proc_info", LOG_PID, LOG_DAEMON);

    setsid();//第二步
    chdir("/");//第三步
    umask(0);//第四步

    for (int i = 0; i < getdtablesize(); i++)
    {
        close(i);//第五步（创建完毕）
    }

    child2 = fork();
    if(child2 == -1)
    {
        perror("child2 fork");
        exit(1);
    }
    else if(child2 == 0)
    {
        syslog(LOG_INFO, "child2 whill sleep for 10s");
        sleep(10);
        syslog(LOG_INFO, "child2 whill exit");
    }
    else
    {
        waitpid(child2, NULL, 0);
        syslog(LOG_INFO, "child1 ntice child2 exit");
        closelog();
        while (1)
        {
            sleep(10);
        }
        
    }
    return 0;
}