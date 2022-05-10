#include <stdio.h>
int main()
{
    int n;
    char c;
    scanf("%d %c",&n,&c);
    int row;
    int lie=n;
    if(lie%2==1){
        row=lie/2+1;
    }
    else{
        row=lie/2;
    }
    for(int i=1;i<=lie;i++){
        printf("%c",c);
    }
    printf("\n");
    for(int i=1;i<=row-2;i++){
        for(int j=1;j<=lie;j++){
            if(j==1||j==lie){
                printf("%c",c);
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    for(int i=1;i<=lie;i++){
        printf("%c",c);
    }



}
