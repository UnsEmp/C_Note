#include <iostream>
#include <cstring>
using namespace std;

#define MAX 7
int HashTable[MAX-1] = {0};
char arr[MAX] = {"PATest"};
int main()
{
    int sum = 0;
    char s[100010];
    scanf("%s",s);
    for(int i = 0;i < strlen(s);i++){ //对输入的每一个元素进行判断
        for(int j = 0;j < MAX - 1;j++){ 
            if(s[i] == arr[j]){ //如果是要找的元素则进行添加记录
                HashTable[j]++;
                sum++;
                break;
            }
        }
    }
    while(sum != 0){
        for(int i = 0;i < MAX - 1;i++){
            if(HashTable[i] > 0){
                printf("%c",arr[i]);
                HashTable[i]--;
                sum--;
            }
        }
    }
    return 0;
}