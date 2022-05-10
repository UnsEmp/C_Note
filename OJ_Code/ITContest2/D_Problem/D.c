#include <string.h>
#include <stdio.h>

#define MAX 110
// strlen() //返回字符串长度
// strcmp() //比较两个字符串的大小

int main() {
    // sizeof(arr) / sizeof(int);
    char arr[MAX], brr[MAX];
    scanf("%s", arr);
    scanf("%s", brr);
    for(int i = 0;i < strlen(arr);i++) {
        if(arr[i] >= 97 && arr[i] <= 122) {
            arr[i] -= 32;
        }
    }
    for(int i = 0;i < strlen(brr);i++) {
        if(brr[i] >= 97 && arr[i] <= 122) {
            brr[i] -= 32;
        }
    }
    if(strcmp(arr, brr) > 0) printf("1");
    else if(strcmp(arr, brr) < 0) printf("-1");
    else printf("0");
    return 0;
}

// 3
// 1 2 2 3 4 5 //数组元素
// 0 1 2 3 4 5 //下标
// 0 5
// 3 5
// 3 3