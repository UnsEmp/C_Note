#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAX = 26 * 26 * 26 * 10 + 1;
vector<int> stu[MAX];
int Transform(string s)
{
    int sum = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            sum = sum * 26 + (s[i] - 'A');
        }
        else{
            sum = sum * 10 + (s[i] - '0');
        }
    }
    return sum;
}
int main()
{
    int n,k;
    cin >> n >> k;
    string r[n];
    string s;
    int serial,number,temp;
    for(int i = 0;i < k;i++){
        cin >> serial >> number;
        while(number--){
            cin >> s;
            temp = Transform(s);
            stu[temp].push_back(serial);
        }
    }
    for(int i = 0;i < n;i++){
        cin >> r[i];
        temp = Transform(r[i]);
        sort(stu[temp].begin(),stu[temp].end());
    }
    for(int i = 0;i < n;i++){
        cout << r[i];
        temp = Transform(r[i]);
        if(stu[temp].size() != 0){
            cout << " " << stu[temp].size();
            for(int i = 0;i < stu[temp].size();i++)
                cout << " " << stu[temp][i];
        }
        else
            cout << " " << stu[temp].size();
        cout << "\n";
    }
    return 0;
}