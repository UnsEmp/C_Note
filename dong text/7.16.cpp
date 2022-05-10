#include <stdio.h>
int main()
{
    int a[4],cnt=1;
    scanf("%d",&a[0]);
    for(int i=1;i<=3;i++){
        a[i]=a[i-1]+1;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(a[j]!=a[i]){
                for(int t=0;t<4;t++){
                    if(a[t]!=a[i]&&a[t]!=a[j]){
                        printf("%d%d%d",a[i],a[j],a[t]);
                        if(cnt%6==0)printf("\n");
                        else printf(" ");
                        cnt++;
                    }
                }
            }
        }
    }
    return 0;
}
