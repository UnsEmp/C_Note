#include <cstdio>
#include <cstring>

int main()
{
    int top = -1,count = 0,cnt = 0,flag = 0;
    char arr[500001];
    gets(arr);
    char brr[50000][20];
    while(arr[++top] == ' ');
    for(int i = top;i < strlen(arr);i++){
        if(arr[i] != ' '){
            brr[cnt][count++] = arr[i];
            flag = 1;
        }
        else{
            if(flag == 1){
                cnt++;
                flag = 0;
            }
            count = 0;
        }
    }
    for(int i = cnt;i >= 0;i--){
        printf("%s",brr[i]);
        i != 0?printf(" "):printf("");
    }
    return 0;
}