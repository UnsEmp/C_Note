#include <bits/stdc++.h>
using namespace std;
class CountIntervals {
public:
    CountIntervals() {

    }
    int cnt = 0;
    set<pair<int,int>> st; 
    void add(int left, int right) {
        if(st.size()) {
            st.insert({left, right});
        }
        else {
            int sum = 0;
            auto t = st.lower_bound(left, 0);
            while(t != st.end() && (*t).second <= left) {
                st.lower_bound()
            }
            sum += (right - left + 1) - sum;
            st.insert({left, right});
            cnt += sum;
        }
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */