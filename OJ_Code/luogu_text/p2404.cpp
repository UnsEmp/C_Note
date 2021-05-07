#include <cstdio>
#include <iostream>
using namespace std;
int n;
int sum = 0,top = -1,count = 0;
int HashTable[10] = {0};

void dfs(int m)
{
    if(sum == n){
        count++;
        for(int i = 0;i < top;i++){
            cout << HashTable[i] << '+';
        }
        if(count%4 == 0 || HashTable[top] == n){
            cout << HashTable[top] << '\n';
        }
        else{
            cout << HashTable[top] << ';';
        }
        return ;
    }
    else if(sum > n)
    return ;
    for(int i = m;i <= n;i++){
        sum += i;
        HashTable[++top] = i;
        dfs(i);
        sum -= i;
        top--;
    }
}

int main()
{
    scanf("%d",&n);
    dfs(1);
    return 0;
}