#include<bits/stdc++.h>
using namespace std;
bool arr[256];
int p = 13,k = 13,h = 13,t = 13;
int main()
{
    fill(arr,arr + 256,true);
    bool flag = true;
    int temp;
    string s;
    cin >> s;
    for(int i = 0,j = 3;i < s.size();i += 3,j += 3){
        int sum = 0;
        for(int t = i;t < j;t++){
            if(s[i] == 'P'){
                temp = 0;
                if(s[t] == 'P'){
                    p--;
                    continue;
                }
                sum += s[t] - '0';
                if(t == i + 1)
                    sum *= 10;
            }
            else if(s[i] == 'K'){
                temp = 13;
                if(s[t] == 'K'){
                    k--;
                    continue;
                }
                sum += s[t] - '0';
                if(t == i + 1)
                    sum *= 10;
            }
            else if(s[i] == 'H'){
                temp = 26;
                if(s[t] == 'H'){
                    h--;
                    continue;
                }
                sum += s[t] - '0';
                if(t == i + 1)
                    sum *= 10;
            }
            else if(s[i] == 'T'){
                temp = 39;
                if(s[t] == 'T'){
                    t--;
                    continue;
                }
                sum += s[t] - '0';
                if(t == i + 1)
                    sum *= 10;
            }
        }
        sum += temp;
        if(!arr[sum])
            flag = false;
        arr[sum] = false;
    }
    if(!flag)
        cout << "GRESKA" << endl;
    else
        cout << p << " " << k << " " << h  << " " << t << endl;
	return 0;
}