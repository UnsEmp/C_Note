#include <cstdio>
#include <cmath>
int main()
{
    int n;
    scanf("%d",&n);
    int count[n]={0},A[5]={0},a;
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(a%5==0&&a%2==0){
            count[0]+=a;
            A[0]++;
        }
        if(a%5==1){
            count[1]+=pow(-1,A[1])*a;
            A[1]++;
        }
        if(a%5==2){
            count[2]++;
            A[2]++;
        }
        if(a%5==3){
            count[3]+=a;
            A[3]++;
        }
        if(a%5==4){
            if(a>count[4]){
                count[4]=a;
                A[4]++;
            }
        }
    }
    for(int i=0;i<5;i++){
        if(A[i]==0){
            printf("N");
        }
        else if(i==3){
            printf("%.1lf",(double)count[i]/A[i]);
        }
        else{
            printf("%d",count[i]);
        }
        printf("%c",i<4?' ':'\n');
    }
    
    
}