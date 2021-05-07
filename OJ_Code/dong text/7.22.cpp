#include <stdio.h>
#include <math.h>
int main()
{
    int t,n=0;
    scanf("%d",&t);
    int trutle=0,rabbit=0;
    while(n<t){
        n++;
        trutle+=3;
        rabbit+=9;
        if(n%10==0){
            if(rabbit>trutle){
                trutle+=90;
                n+=30;
                if(n>t){
                    trutle-=(n-t)*3;
                }
            }
        }
    }
    if(trutle>rabbit){
        printf("@_@ %d",trutle);
    }
    else if(trutle<rabbit){
        printf("^_^ %d",rabbit);
    }
    else{
        printf("-_- %d",trutle);
    }
    return 0;
}

