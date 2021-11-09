#include <stdio.h>
#include <math.h>
#include <string.h>

char* change(char* a) { //改变数组中元素前后位置
    int len = strlen(a);
    char ch;
    for(int i = 0;i < len / 2;i++) {
        ch = a[len - i - 1];
        a[len - i - 1] = a[i];
        a[i] = ch;
    }
    return a;
}

char* add(char *a, char *b) {
    // char c[505];
    int len1 = strlen(a), len2 = strlen(b);
    int bit = 0, tmp = 0, top = 0;
    while(top < len1 || top < len2) {
        tmp = 0;
        if(top < len1) tmp += (a[top] - '0');
        if(top < len2) tmp += (b[top] - '0');
        tmp += bit;
        bit = tmp / 10;
        tmp %= 10;
        a[top++] = tmp + '0';
    }
    while(bit) {
        tmp = bit;
        bit = tmp / 10;
        tmp %= 10;
        a[top++] = tmp + '0';
    }
    a[top] = '\0';
    return a;
}

int main() {
    char a[505], b[505];
    char *c;
    scanf("%s", a);
    scanf("%s", b);
    change(a);
    change(b);
    c = add(a, b);
    for(int i = strlen(c) - 1;i >= 0;i--) {
        printf("%c",c[i]);
    }
    return 0;
}



/*
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
*/