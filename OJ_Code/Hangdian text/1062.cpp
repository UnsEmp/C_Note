#include <cstdio>
#include <cstring>
#define MAX 1000
int main()
{
    int n;
    int cnt = 0;
    int count = 0,start;
    scanf("%d",&n);
    getchar();
    char arr[MAX];
    for(int i = 0;i < n;i++){
        gets(arr);
        for(int j = 0;j <= strlen(arr);j++){
            if(arr[j] == ' ' || j == strlen(arr)){
                for(int t = j-1;t >= j - count;t--){
                    printf("%c",arr[t]);
                }
                if(j != strlen(arr)){
                    printf(" ");
                }
                count = 0;
            }
            else{
                count++;
            }
        }
        printf("\n");
    }
}