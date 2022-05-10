#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n, count = 0;
    string s;
    map<string, int> mp;
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> s;
        if(!mp[s]) {
            count++;
            mp[s]++;
        }
    }
    cout << count << endl;
    return 0;
}