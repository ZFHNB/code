#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int a1[200]={0};
  int a2[8]={0};

  for(int i = 0; i<20230408; i++){
    a2[0]++;
    for(int j = 0 ;j<8;j++){
      if(a2[j]>=10){
        a2[j+1]++;
        a2[j]=0;
      }
    }
    for(int k = 0; k<8; k++){
      a1[k]+=a2[k];
    }
    for(int l = 0; l<200;l++){
      if(a1[l]>=10){
        a1[l+1]+=a1[l]/10;
        a1[l]=a1[l]%10;
      }
    }
  }

  for(int i=199;i>=0;i--)
    printf("%d",a1[i]);
  return 0;
}
