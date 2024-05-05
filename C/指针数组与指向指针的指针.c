#include <stdio.h>

int main(){

    char *cBooks[6] = {
        "《C程序设计语言》",
        "《C专家编程》",
        "《c和指针》",
        "《c陷阱与缺陷》",
        "《C Primer Plus》",
        "《带你学C带你飞》"
    };

    char **byFishC;
    char **jiayuLoves[5];

    byFishC = &cBooks[5];

    for(int i=0;i<5;i++){
        jiayuLoves[i] = &cBooks[i];
    }

    printf("*byFishC: %s\n",*byFishC);
    printf("cBooks[5]: %s\n",cBooks[5]);
    printf("byFishC: %p\n",byFishC);
    printf("&cBooks[5]: %p\n\n\n",&cBooks[5]);

    printf("byFishc: %s\n",*byFishC);
    printf("jiayuLoves:\n");
    for(int i=0;i<5;i++){
        printf("%s\n",*jiayuLoves[i]);
    }

    return 0;
}
