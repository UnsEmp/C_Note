#include <iostream>
#include <cstring>
using namespace std;
#define MAX 128
int HashTable[MAX];


int swap(int n,int m)
{
    int sum = 0;
    for(int i = 0;n != 0;i++){
        sum += (n % 10) * g(m,i);
        n /= 10;
    }
    return sum;
}

int g(int m,int n)
{
    int sum = 1;
    for(int i = 0;i < n;i++)
    sum *= m;
    return sum;
}

int fun(char arr[],int n)
{
    int sum = 0;
    for(int i = 0;i < strlen(arr);i++){
        sum += HashTable[arr[i]] * g(n,i);
    }   
}

int main()
{
    int N1[10],N2[10];
    int temp1,temp2;
    char tag,radix;
    cin >> N1 >> N2 >> tag >> radix;
    for(char ch = '0';ch <= '9';ch++){
        HashTable[ch] = ch - '0';
    }
    for(char ch = 'a';ch <= 'z';ch++){
        HashTable[ch] = ch - 'a' + 10;
    }
    if(tag == 1){
        temp1 = fun(N1,radix);
        for(int i = 2;i <= )
    }
    return 0;
}