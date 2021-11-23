#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdbool>
#include <string>
using namespace std;

#define MAX 256
bool HashTable[MAX];

int main()
{
    string S1,S2;
    char ch;
    getline(cin,S1);
    getline(cin,S2);
    memset(HashTable,true,sizeof(HashTable));
    for(int i = 0;i < S1.size();i++){
        ch = S1[i];
        if(ch >= 'A' && ch <= 'Z')
        ch += 32;
        HashTable[ch] = false;
    }
    for(int i = 0;i < S2.size();i++){
        ch = S2[i];
        if(ch >= 'A' && ch <= 'Z')
        ch += 32;
        if(HashTable[ch] != false){
            if(HashTable['+'] != false)
            printf("%c",S2[i]);
            else{
                if(S2[i] >= 'A' && S2[i] <= 'Z') 
                continue;
                else 
                printf("%c",ch);
            }
        }
    }
    return 0;
}