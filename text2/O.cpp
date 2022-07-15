#include <bits/stdc++.h>
using namespace std;

int main() {
    char ch[20] = {"明天进攻"};
    printf("%d\n", strlen(ch));
    for(int i = 0;i < strlen(ch);++i) ch[i] ^= 5;
    cout << "\n";
    printf("%s\n", ch);
    for(int i = 0;i < strlen(ch);++i) ch[i] ^= 5;
    printf("%s\n", ch);
    return 0;
}