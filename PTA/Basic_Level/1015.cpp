#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Data
{
    string ID;
    int D;
    int C;
    int sum = 0;
    int flag;
};

bool compare(Data a,Data b)
{
    if(a.flag != b.flag)
        return a.flag < b.flag;
    else if(a.sum != b.sum)
        return a.sum > b.sum;
    else if(a.D != b.D)
        return a.D > b.D;
    else
        return a.ID < b.ID;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,M,H;
    cin >> N >> M >> H;
    Data stu[N];
    for(int i = 0;i < N;i++){
        cin >> stu[i].ID >> stu[i].D >> stu[i].C;
        if(stu[i].C < M || stu[i].D < M){
            N--;
            i--;
            continue;
        }
        stu[i].sum = stu[i].C + stu[i].D;
        if((stu[i].C >= H) && (stu[i].D >= H))
            stu[i].flag = 1;
        else if((stu[i].C < H) && (stu[i].D >= H))
            stu[i].flag = 2;
        else if((stu[i].D >= stu[i].C))
            stu[i].flag = 3;
        else
            stu[i].flag = 4;
    }
    sort(stu,stu+N,compare);
    cout << N << "\n";
    for(int i = 0;i < N;i++)
        cout << stu[i].ID << " " << stu[i].D << " " << stu[i].C << "\n";
    return 0;
}