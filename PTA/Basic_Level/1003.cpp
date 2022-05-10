#include <bits/stdc++.h>
using namespace std;

bool methodone(string s)
{
    for(int i = 0;i < s.size();i++){
        if(s[i] == 'P' || s[i] == 'A' || s[i] == 'T'){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x,y,z;
    
    cin >> n;
    while(n--){
        bool flag = true;
        string s;
        cin >> s;
        int p_pos = -1,t_pos = -1,num_p = 0,num_t = 0,num_a = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == 'P'){
                num_p++;
                p_pos = i;
            }
            else if(s[i] == 'T'){
                num_t++;
                t_pos = i;
            }
            else if(s[i] == 'A'){
                num_a++;
            }
            else{
                flag = false;
                break;
            }
        }
        if(num_p != 1 || num_t != 1)
            flag = false;
        int x,y,z;
        x = p_pos;
        y = t_pos - p_pos - 1;
        z = s.size() - t_pos - 1;
        while(y > 1){
            y -= 1;
            z -= x;
        }
        if(x != z || y == 0 || t_pos < p_pos)
            flag = false;

        if(flag)
            cout << "YES" << endl;
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}