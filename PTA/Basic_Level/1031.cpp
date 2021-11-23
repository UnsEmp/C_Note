#include <iostream>
#include <string>
using namespace std;
int q[17] = {
    7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2
};
char m[12] = {"10X98765432"};
int main()
{
    int n;
    bool flag = true;
    int count = 0;
    string s;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> s;
        int sum = 0;
        flag = true;
        for(int j = 0;j < 17;j++){
            if(s[j] < 48 || s[j] > 57){
                flag = false;
                break;
            }
            sum += (s[j] - '0') * q[j];
        }
        if(!flag){
                cout << s << endl;
                count++;
        }
        else if(m[sum % 11] != (s[s.size() - 1])){
            cout << s << endl;
            count++;
        }
    }
    if(count == 0)
        cout << "All passed" << endl;
    return 0;
}