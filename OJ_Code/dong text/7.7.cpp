#include <cstdio>
int main()
{
    int shi,fen;
    char a[5]={"AM"},b[5]={"PM"};
    scanf("%d:%d",&shi,&fen);
    if(shi>=12){
        if(shi>12){
            shi-=12;
        }
        printf("%d:%d %s",shi,fen,b);
    }
    else{
        printf("%d:%d %s",shi,fen,a);
    }
}