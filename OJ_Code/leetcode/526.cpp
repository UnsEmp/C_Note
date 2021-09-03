#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countArrangement(int n) {
        vector<int> arr(n);
        for(int i = 0;i < n;i++) {
            arr[i] = i + 1;
        }
        int count = 0;
        sort(arr.begin(), arr.end());
        do {
            for(int i = 0;i < arr.size();i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";
            if(judge(arr)) {
                count++;
            }
        }while(next_permutation(arr.begin(), arr.end()));
        return count;
    }
    bool judge(vector<int> & arr) {
        bool flag = true;
        for(int i = 0;i < arr.size();i++) {
            if(arr[i] % (i + 1) == 0 || (i + 1) % arr[i] == 0)
                continue;
            else {
                flag = false;
                break;
            }
        }
        return flag;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().countArrangement(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}