#include <cstdio>
#include <cstring>
#include <cstdbool>
#define MAX 100
#define SIZE 1010

int HashTable[MAX] = {0};

int changefunc(char ch);

int main()
{
    int beyond = 0,lack = 0;
    char arr[SIZE],brr[SIZE];
    scanf("%s",arr);
    scanf("%s",brr);
    for(int i = 0;i < strlen(arr);i++){
        int id = changefunc(arr[i]);
        HashTable[id]++;
    }
    for(int i = 0;i < strlen(brr);i++){
        int id = changefunc(brr[i]);
        HashTable[id]--;
        if(HashTable[id] < 0)
        lack++;
    }
    if(lack != 0)
    printf("No %d",lack);
    else{
        printf("Yes %d",strlen(arr) - strlen(brr));
    }
    return 0;
}

int changefunc(char ch)
{
    int sum = 0;
    if(ch >= '0' && ch <= '9'){
        sum += ch - '0';
    }
    else if(ch >= 'A' && ch <= 'Z'){
        sum += ch - 'A' + 10;
    }
    else if(ch >= 'a' && ch <= 'z'){
        sum += ch - 'a' + 36;
    }
    return sum;
}