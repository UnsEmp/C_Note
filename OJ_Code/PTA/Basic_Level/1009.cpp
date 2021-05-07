#include <stdio>
#include <cstring>

int main()
{
    char arr[90];
    int len;
    int row = 0,lie = 0;
    gets(arr);
    len = strlen(arr);
    char brr[90][90];
    for(int i = 0;i < len;i++){
        if(arr[i] != ' '){
            brr[row][lie++] = arr[i];
        }
        else{
            brr[row++][lie] = '\0';
            lie = 0;
        }
    }
    for(int i = row;i >= 0;i--){
        printf("%s",brr[i]);
        if(i != 0)
        printf(" ");
    }
    return 0;
}