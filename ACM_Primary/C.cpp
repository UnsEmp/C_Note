#include<bits/stdc++.h>
using namespace std;
vector<int> a,b;
int num(int temp,int late,int flag)
{
    int i = temp,j = temp,sum = 0;
    while(i != late && j != late){
        if(flag == 1 && a[i] > b[j] || flag == -1 && a[i] < b[j]){
            sum++;
            i += flag;
            j += flag;
        }
        else
            j += flag;
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,temp;
    cin >> n;
    vector<bool> collec(2 * n + 1);
    for(int i = 0;i < n;i++){
        cin >> temp;
        b.push_back(temp);
        collec[temp] = true;
    }
    for(int i = 1;i <= 2 * n;i++){
        if(collec[i] != true)
            a.emplace_back(i);
    }
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.begin() + b.size() / 2,greater<int>());
    sort(b.begin() + b.size() / 2,b.end(),greater<int>());
    cout << num(0,b.size() / 2,1) + num(b.size() - 1,b.size() / 2 - 1,-1) << endl;
	return 0;
}