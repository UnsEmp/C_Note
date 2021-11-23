#include <bits/stdc++.h>
using namespace std;

struct score
{
    int C;
    int M;
    int E;
    int A;
    char ch;
}stu[1000000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<score> c,m,e,a; 
    for(int i = 0;i < n;i++){
        cin >> stu[i].ID >> stu[i].C >> stu[i].M >> stu[i].E;
        stu[i].A = (stu[i].C + stu[i].M + stu[i].E) / 3;
    }
    
    return 0;
}