#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Transform(vector<int> &index)
{
    int sum = 0;
    for(int i = 0;i < index.size();i++){
        sum = sum * 10 + index[i];
    }
    return sum;
}

int main()
{
    int cnt;
    vector<char> num;
    vector<int> index;
    string s;
    cin >> s;
    string::iterator it = s.begin();
    int i;
    if(s[0] == '-')
        cout << '-';
    for(i = 1;s[i] != 'E';i++){
        if(s[i] >= '0' && s[i] <= '9'){
            num.push_back(s[i]);
        }
    }
    for(int j = i + 1;j < s.size();j++){
        if(s[j] >= '0' && s[j] <= '9'){
            index.push_back(s[j] - '0');
        }
    }
    cnt = Transform(index);
    if(cnt == 0){
        cout << num[0] << '.';
        for(int t = 1;t < num.size();t++)
            cout << num[t];
        return 0;
    }
    if(s[i + 1] == '+'){
        if(cnt >= num.size() - 1){
            for(int i = 0;i < num.size();i++)
                cout << num[i];
            for(int t = 0;t < cnt - num.size() + 1;t++)
                cout << '0';
        }
        else{
            num.insert(num.begin() + cnt + 1,'.');
            for(int i = 0;i < num.size();i++)
                cout << num[i];
        }
    }
    else{
        if(cnt == 1){
            cout << "0.";
            for(int i = 0;i < num.size();i++)
                cout << num[i];
        }
        else{
            cout << "0.";
            for(int i = 0;i < cnt - 1;i++)
                cout << '0';
            for(int i = 0;i < num.size();i++)
                cout << num[i];
        }
    }
    return 0;
}