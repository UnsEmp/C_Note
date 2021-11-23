#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        long long sum = w;
        if(sum >= capital[n - 1] && k == n) {
            for(int i = 0;i < n;i++) {
                sum += profits[i];
            }
            return sum;
        }
        vector<pair<int, int>> ans;
        // unordered_map<int ,int> mp;
        for(int i = 0;i < n;i++) {
            ans.push_back({profits[i], capital[i]});
        }
        sort(ans.begin(), ans.end(), [&](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });
        priority_queue<int, vector<int>, less<int>> q;
        int i = 0, count = 0;
        // return 0;
        while(i < n && count < k) {
            while(sum >= ans[i].second && i < n) {
                q.push(ans[i].first);
                i++;
            }
            if(q.empty()) break;
            int tmp = q.top();
            cout << tmp << endl;
            q.pop();
            sum += tmp;
            count++;
        }
        while(count < k) {
            int tmp = q.top();
            q.pop();
            sum += tmp;
            count++;
        }
        return sum;
        
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        int k = stringToInteger(line);
        getline(cin, line);
        int w = stringToInteger(line);
        getline(cin, line);
        vector<int> profits = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> capital = stringToIntegerVector(line);
        
        int ret = Solution().findMaximizedCapital(k, w, profits, capital);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}