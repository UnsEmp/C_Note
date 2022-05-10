#include <stdio.h>
#define MAX 1010
int main() {
    int n;
    scanf("%d" ,&n);
    int arr[MAX] = {0}, brr[8] = {0}, Hash[MAX] = {0};
    for(int i = 0;i < 7;i++) {
        scanf("%d", & arr[i]);
        Hash[arr[i]]++; //区分中奖的和不中奖的号码
    }
    for(int i = 0;i < n;i++) {

        int count = 0; // 记录彩票的中奖个数
        for(int j = 0;j < 7;j++) {
            int tmp;
            scanf("%d", &tmp);
            if(Hash[tmp]) count++;
        }
        brr[count]++; //brr[7] == 特等奖个数 brr[6] == 一等奖 // 

    }
    for(int i = 7;i >= 1;i--) {
        printf("%d ", brr[i]);
    }
    return 0;
}


// 23 31 1 14 19 17 18

// arr[23] = 1;
// arr[22] = 0;

// 12 8 9 23 1 16 7

2
23 31 1 14 19 17 18

12 8 9 23 1 16 7 

11 7 10 21 2 9 31