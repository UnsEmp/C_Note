#include <stdio.h>
#include <string.h>
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    char a[n][11];
    for(int i=0;i<n;i++){
        scanf("%s",a[i]);
    }
    char c[11];
    for(int i=n-1;i>0;i--,k--){
         if(k==0){
            break;
        }
        for(int j=0;j<i;j++){
            if(strcmp(a[j],a[j+1])>0){
                strcpy(c,a[j]);
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],c);
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%s\n",a[i]);
    }
}