#include <bits/stdc++.h>
using namespace std;

int n;
// stack<int> st;

void dfs(int idx, stack<int> st) {
    if(idx == n + 1) {
        while(st.size()) {
            cout << st.top();
            st.pop();
        }
        cout << "\n";
        return ;
    }
    st.push(idx);
    dfs(idx + 1, st);
	st.pop();
	
	cout << idx;
    dfs(idx + 1, st);
}

int main() {
    cin >> n;
    stack<int> st;
    dfs(1, st);
    return 0;
}