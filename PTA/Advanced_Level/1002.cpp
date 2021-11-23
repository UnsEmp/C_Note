#include <cstdio>
double arr[1010] = {0};
int main()
{
    int n,index;
    int count = 0;
    double coeff;
    for(int j = 0;j < 2;j++){
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            scanf("%d %lf",&index,&coeff);
            if(arr[index] == 0 && coeff != 0.0)
                count++;
            arr[index] += coeff;
            if(arr[index] == 0)
                count--;
        }
    }
    if(count == 0){
        printf("0");
        return 0;
    }
    printf("%d ",count);
    for(int i = 1009;i >= 0;i--){
        if(arr[i] != 0){
            printf("%d %.1lf",i,arr[i]);
            if(--count)
                printf(" ");
        }
    }
    return 0;
}