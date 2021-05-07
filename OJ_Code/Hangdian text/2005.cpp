#include <cstdio>
int num(int year,int month)
{
    int a;
    switch(month){
        case 1:a = 31;break;
        case 2:if((year%4==0&&year%100!=0)||(year%1000==0)){
            a = 29;
        }
        else{
            a = 28;
        }break;
        case 3:a = 31;break;
        case 4:a = 30;break;
        case 5:a = 31;break;
        case 6:a = 30;break;
        case 7:a = 31;break;
        case 8:a = 31;break;
        case 9:a = 30;break;
        case 10:a = 31;break;
        case 11:a = 30;break;
        case 12:a = 31;break;
    }
    return a;
}
int main()
{
    int year,month,day;
    int sum;
    while(scanf("%d/%d/%d",&year,&month,&day) != EOF)
    {
        sum = 0;
        for(int i = 1;i < month;i++){
            sum += num(year,i);
        }
        printf("%d\n",sum+day);
    }
}