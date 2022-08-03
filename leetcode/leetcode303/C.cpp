#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
public:
    map<string, int> score;
    map<string, set<pair<int, string>>> mp;
    map<string, string> cu;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0;i < n;++i) {
            score[foods[i]] = ratings[i];
            mp[cuisines[i]].insert({ratings[i], foods[i]});
            cu[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        auto t = mp[cu[food]].find({score[food], food});
        mp[cu[food]].erase(t);
        mp[cu[food]].insert({newRating, food});
        score[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto t = mp[cuisine].lower_bound({(*mp[cuisine].rbegin()).first, ""});
        return (*t).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */