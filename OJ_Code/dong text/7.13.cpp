#include <stdio.h>
int main()
{
    double open,high,low,close;
    scanf("%lf %lf %lf %lf",&open,&high,&low,&close);
    if(close<open){
        printf("BW-Solid");
    }
    else if(close>open){
        printf("R-Hollow");
    }
    else{
        printf("R-Cross");
    }
    if((high>open&&high>close)&&(low>=open||low>=close)){
        printf(" with Upper Shadow");
    }
    else if((low<open&&low<close)&&(high<=open||high<=close)){
        printf(" with Lower Shadow");
    }
    else if((high>open&&high>close)&&(low<open&&low<close)){
        printf(" with Lower Shadow and Upper Shadow");
    }
    return 0;
}