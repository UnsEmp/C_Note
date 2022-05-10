#include <stdio.h>
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n],t;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=n-1;k!=0;i--,k--){
        for(int j=0;j<i;j++){
            if(a[j]>a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        if(i<n-1){
            printf(" ");
        }
    }


}