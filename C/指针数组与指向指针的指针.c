#include <stdio.h>

int main(){

    char *cBooks[6] = {
        "��C����������ԡ�",
        "��Cר�ұ�̡�",
        "��c��ָ�롷",
        "��c������ȱ�ݡ�",
        "��C Primer Plus��",
        "������ѧC����ɡ�"
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
