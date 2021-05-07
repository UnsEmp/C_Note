#include <cstdio>
#include <cmath>
int main()
{
    int a,count=0,t;
    scanf("%d",&a);
    if(a==0){
        count++;
    }
    for(int i=a;i!=0;i/=10){
        count++;
    }

    if(a<0){
        printf("fu ");
        a=-a;
    }
    while(count!=0){
        t=pow(10,count-1);
        switch(a/t){
            case 0:printf("ling");break;
            case 1:printf("yi");break;
            case 2:printf("er");break;
            case 3:printf("san");break;
            case 4:printf("si");break;
            case 5:printf("wu");break;
            case 6:printf("liu");break;
            case 7:printf("qi");break;
            case 8:printf("ba");break;
            case 9:printf("jiu");break;
        }
        if(count!=1){
            printf(" ");
        }
        a=a%t;
        count--;
    }
    return 0;
}