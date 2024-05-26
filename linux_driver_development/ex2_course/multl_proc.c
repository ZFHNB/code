#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t child1,child2;
    child1=fork();
    if(child1==-1)
    {
        printf("child1 error \r\n");
        exit(0);
    }
    else if(child1==0)
    {
        printf("child1:ls -l \r\n");
        if((execlp("ls","ls","-l",NULL))<0)
        {
            printf("excelp error.");
        }
    }
    else
    {
        child2=fork();
        if(child2==-1)
        {
            printf("child2 fork error.");
            exit(1);
        }
        else if(child2==0)
        {
            printf("child2:sleep(5)");
            sleep(5);
            exit(0);
        }

        //father proc
        printf("father process \r\n");
        pid_t child=waitpid(child1,NULL,0);

        if(child==child1)
        {
            printf("child1 exit \r\n");
        }
        do
        {
            child=waitpid(child2,NULL,WNOHANG);
            if(child==0)
            {
                printf("child2 do not exit \r\n");
                sleep(1);
            }
        }
        while(child==0);

        if(child==child2)
        {
            printf("child2 sleep(5) \r\n");
            exit(0);
        }
    }
    exit(0);
}