#include <stdio.h>
#include <iostream>
using namespace std;

void Print_Factorial ( const int N );

int main()
{
    int N;

    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}
void Print_Factorial ( const int N )
{
        int a[500000]= {0};
    a[0]=1;
    int temp;
    int size=0;
    int bit=0;

    if(N>0){
        for(int i=1;i<=N;i++){
            for(int j=0;j<=size;j++){
                temp=a[j]*i+bit;
                a[j]=temp%10;
                bit=temp/10;
            }
            while(bit){
                a[++size]=bit%10;
                bit/=10;
            }
        }
        for(int t=size;t>=0;t--){
            printf("%d",a[t]);
        }
    }
    else if(N==0){
        printf("1");
    }
    else{
        printf("Invalid input");
    }
}