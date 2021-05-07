#include <cstdio>
#include <cstring>
int main()
{
    int a,b,flag = 0;
    scanf("%d",&a);
    char ch;
    while((ch = getchar())!= '='){
        scanf("%d",&b);
        if((ch == '/') && (b == 0)){
            flag = 1;
            break;
        }
        switch (ch)
        {
        case '+':a += b;break;
        case '-':a -= b;break;
        case '*':a *= b;break;
        case '/':a /= b;break;
        default:flag = 1;break;
        }
        if(flag == 1){
            break;
        }
    }
    if(flag){
        printf("ERROR");
    }
    else{
        printf("%d",a);
    }
    return 0;
}
