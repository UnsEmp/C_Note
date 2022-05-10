#include <cstdio>

#define MAX 60

int main()
{
    int k,temp;
    scanf("%d",&k);
    int arr[MAX],brr[MAX],crr[MAX];
    char ar[5] = {'S','H','C','D','J'};
    for(int i = 1;i <= 54;i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 1;i <=54;i++){
        brr[i] = i;
    }
    for(int i = 0;i < k;i++){
        for(int j = 1;j <= 54;j++){
            crr[arr[j]] = brr[j];
        }
        for(int j = 1;j <= 54;j++){
            brr[j] = crr[j];
        }
    }
    int cnt,bit;
    for(int i = 1;i <= 54;i++){
        cnt = brr[i] / 13;
        bit = brr[i] % 13;
        if(bit == 0){
            bit = 13;
            cnt--;
        }
        printf("%c%d",ar[cnt],bit);
        if(i != 54)
        printf(" ");
    }
    return 0;
}