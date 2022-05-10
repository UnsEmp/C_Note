#include <bits/stdc++.h>
using namespace std;

const int N =1e7+10;

char p[N];
int ne[N];
char ans[N];

void GetNext()
{
    int Len = strlen(p);
    ne[0] = -1;
    int k = ne[0];
    int j = 0;
    while (j < Len - 1)
    {
        if (k == -1 || p[j] == p[k]) 
        {
            ne[j+1] = k+1;
            k++;j++;
        }
        else 
        {
            k = ne[k];
        }
    }
}
 
int main()
{
    scanf("%s", p);
    int n = strlen(p);
    GetNext();
    int i;
    for(i = 0;i <= ne[n - 1];++i) ans[i] = p[i];
    ans[i] = '\0'; 
    printf("%s\n", ans);
    return 0;
}

