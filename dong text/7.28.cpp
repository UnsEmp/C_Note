#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int mon[n];
    for(int i=0;i<n;i++){
        mon[i]=i+1;
    }
    int left=n,cnt=0,i=0;
    while(left!=1){
        if(mon[i]!=0){
            cnt++;
        }
        if(cnt==3){
            mon[i]=0;
            cnt=0;
            left--;
        }
        i++;
        if(i==n){
            i=0;
        }
    }
    for(int j=0;j<n;j++){
        if(mon[j]!=0){
            printf("%d",mon[j]);
        }
    }
    return 0;
}