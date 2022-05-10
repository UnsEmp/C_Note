#include <iostream>
using namespace std;

int sum = 0;
int n,count = 0,pos = -1;
int result[31];
void DFS(int x)
{
    if(sum == n)
    {
        count++;
        cout << n << '=';
        for(int i = 0;i < pos;i++)
        cout << result[i] << '+';
        if(count % 4 == 0 || result[pos] == n)
        cout << result[pos] << '\n';
        else
        cout << result[pos] << ';';
        return ;
    }
    else if(sum > n)
    return ;
    for(int i = x;i <= n;i++)
    {
        result[++pos] = i;
        sum += i;
        DFS(i);
        sum -= i;
        pos--;
    }
}

int main()
{
    cin >> n;
    DFS(1);
    return 0;
}