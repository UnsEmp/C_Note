#include <stdio.h>
#include <stdbool.h>

bool judge(int n) {
    int arr[4], count = 0;
    while(n) {
        arr[count++] = n % 10;
        n /= 10;
    }
    bool flag = true;
    for(int i = 0;i < 4;i++) {
        for(int j = 0;j < 4;j++) {
            if(i == j) continue;
            if(arr[i] == arr[j]) {
                flag = false;
                break;
            }
        }
        if(!flag) break; 
    }
    return flag;
}

int main() {
    // bool flag = true; // false;
    int num, i;
    scanf("%d", &num);
    for(i = num + 1;i <= 10000;i++) {
        if(judge(i)) break; 
    }
    printf("%d", i);
     
}