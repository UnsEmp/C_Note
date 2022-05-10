#include <cstdio>
int main()
{
    int year,time;
    double sum;
    scanf("%d %d",&year,&time);
    if(year<5&&time<40){
        sum=time*30;
    }
    else if(year<5&&time>=40){
        sum=40*30+(time-40)*30*1.5;
    }
    else if(year>=5&&time<40){
        sum=time*50;
    }
    else if(year>=5&&time>=40){
        sum=40*50+(time-40)*50*1.5;
    }
    printf("%.2lf",sum);
}