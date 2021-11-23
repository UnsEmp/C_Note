#include <stdio.h>
#define CLK_TCK 100 
int main()
{
    long long c1,c2;
    double time;
    scanf("%ld %ld",&c1,&c2);
    time=(c2-c1)/CLK_TCK;
    double shi,fen,miao;
    shi=time/3600;
    fen=(time%3600)/60;
    if(((time%3600)%60)>=0.4){
        miao=time%3600%60+1;
    }
    else{
        miao=time%3600%60;
    }
    printf("%.0lf:%.0lf:%.0lf",shi,fen,miao);


}