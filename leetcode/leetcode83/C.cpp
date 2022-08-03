#include <bits/stdc++.h>
using namespace std;

// class map_value_finder
// {
// public:
//        map_value_finder( const std:: string &cmp_string):m_s_cmp_string(cmp_string){}
//         bool  operator ()( const std::map< int, std:: string>::value_type &pair)
//        {
//              return pair.second == m_s_cmp_string;
//        }
// private:
//          const std:: string &m_s_cmp_string;                    
// };


// class NumberContainers {
// public:
//     NumberContainers() {

//     }
//     map<int, string> mp, sign;
//     void change(int index, int number) {
//         // mp[index] = number;
//         if(sign[index] != "") {
//             auto t = find_if(mp.begin(), mp.end(), map_value_finder(sign[index]));
//             mp.erase(t);
//         }
//         mp.insert(make_pair(index, to_string(number)));
//         sign[index] = to_string(number);
//     }
    
//     int find(int number) {
//        auto t = find_if(mp.begin(), mp.end(), map_value_finder(to_string(number)));
//        if(t == mp.end()) return -1;
//        return t->first;
//     }
// };

// /**
//  * Your NumberContainers object will be instantiated and called as such:
//  * NumberContainers* obj = new NumberContainers();
//  * obj->change(index,number);
//  * int param_2 = obj->find(number);
//  */


class NumberContainers {
public:
    NumberContainers() {

    }
    set<pair<int, int>> st; //num index
    map<int, int> mp;
    void change(int index, int number) {

        if(!mp[index]) {
            st.insert({number, index});
        }
        else {
            auto t = st.lower_bound({mp[index], index});
            st.erase(t);
            st.insert({number, index});
        }

        mp[index] = number;
    }
    
    int find(int number) {

        auto t = st.lower_bound({number, 0});
        if(t != st.end() && (*t).first == number) return (*t).second;
        return -1;

    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */