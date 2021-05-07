#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define MAX 27
using namespace std;

int HashTable[MAX] = {0}; 

int main()
{
    string s;
    getline(cin,s);
    for(int i = 0;i < s.size();i++){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] += 32;
            }
            HashTable[s[i] - 97]++;
        }
    }
    int k = 0;
    for(int i = 0;i < MAX;i++){
        if(HashTable[i] > HashTable[k])
        k = i;
    }
    printf("%c %d",'a' + k,HashTable[k]);
    return 0;
}