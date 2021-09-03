#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 1) {
            return chars.size();
        }

        int count = 1;
        int size = chars.size();
        vector<char> arr;
        int i;
        for(i = 1;i < size;i++) {
            if(chars[i] != chars[i - 1]) {
                if(count > 1) {
                    arr.push_back(chars[i - 1]);
                    string s = to_string(count);
                    for(int j = 0;j < s.size();j++) {
                        arr.push_back(s[j]);
                    }
                }
                else {
                    arr.push_back(chars[i - 1]);
                }
                count = 1;
            }
            else {
                count++;
            }
        }
        //判断chars数组中最后两个元素是否相同
        if(chars[size - 1] != chars[size - 2]) {
            arr.push_back(chars[size - 1]); //不相同将最后一个元素加入 arr 数组中
        }
        else {
            arr.push_back(chars[i - 1]); // 相同
            string s = to_string(count);
            for(int j = 0;j < s.size();j++) {
                arr.push_back(s[j]);
            }
        }

        for(int i = 0;i < arr.size();i++) {
            chars[i] = arr[i];
        }
        return arr.size();
    }
};