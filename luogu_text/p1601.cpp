#include <cstdio>
#include <cstring>
#define MAX 600

int main()
{
    char arr[MAX],brr[MAX];
    int crr[MAX];
    scanf("%s",arr);
    scanf("%s",brr);
    int temp = 0,bit = 0,cnt = 0,count = 0;
    int len1,len2;
    len1 = strlen(arr);
    len2 = strlen(brr);
    while(len1 != 0 && len2 != 0){
        temp = (arr[--len1] - '0') + (brr[--len2] - '0') + bit;
        cnt = temp % 10;
        bit = temp / 10;
        crr[count++] = cnt;
    }
    while(bit || len1 != 0 || len2 != 0){
        if(len1 != 0){
            bit += (arr[--len1] - '0');
        }
        else if(len2 != 0){
            bit += (brr[--len2] - '0');
        }
        cnt = bit % 10;
        bit /= 10;
        crr[count++] = cnt;
    }
    for(int i = count - 1;i >= 0;i--){
        printf("%d",crr[i]);
    }
}