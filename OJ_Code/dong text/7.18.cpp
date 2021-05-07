#include <stdio.h>
#include <math.h>
double a3,a2,a1,a0;
double f(double x);
int main()
{
    double a,b;
    scanf("%lf %lf %lf %lf",&a3,&a2,&a1,&a0);
    scanf("%lf %lf",&a,&b);
    double left=a,right=b,mid;
    while(right-left>0.001&&f(right)*f(left)<=0){
        if(f(left)==0){
            printf("%.2lf",left);
            return 0;
        }
        if(f(right)==0){
            printf("%.2lf",right);
            return 0;
        }
        mid=(right+left)/2;
        if(f(mid)==0){
            printf("%.2lf",mid);
            return 0;
        }
        if(f(left)*f(mid)<0){
            right=mid;
        }
        else{
            left=mid;
        }
    }
    printf("%.2lf",(right+left)/2);
    return 0;
}
double f(double x)
{
    double y;
    y=a3*pow(x,3)+a2*pow(x,2)+a1*x+a0;
    return y;
}