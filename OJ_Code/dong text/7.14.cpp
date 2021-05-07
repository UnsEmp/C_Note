#include <stdio.h>
int main()
{
    int a,b;
    int sum=0,t=1;
    scanf("%d %d",&a,&b);
    while(a!=b+1){
    sum+=a;
    printf("%5d",a++);
    if(t%5==0)printf("\n");
    t++;
    }
    if((t-1)%5!=0)printf("\n");
    printf("Sum = %d",sum);
    return 0;
}
