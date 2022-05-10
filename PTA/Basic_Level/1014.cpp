#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
char arr[] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
int main()
{
    int i;
    string s1,s2,r1,r2;
    cin >> s1 >> s2 >> r1 >> r2;
    for(i = 0;i < s1.size() && i < s2.size();i++){
        if((s1[i] == s2[i]) && (s1[i] >= 'A' && s1[i] <= 'G')){
            switch(s1[i] - 'A' + 1){
                case 1:printf("MON ");break;
                case 2:printf("TUE ");break;
                case 3:printf("WED ");break;
                case 4:printf("THU ");break;
                case 5:printf("FRI ");break;
                case 6:printf("SAT ");break;
                default:printf("SUN ");
            }
            break;
        }
    }
    for(i++;i < s1.size() && i < s2.size();i++){
        if(s1[i] == s2[i]){
            if(s1[i] >= 'A' && s1[i] <= 'N'){
                printf("%02d:",s1[i] - 'A' + 10);
                break;
            }
            else if(s1[i] >= '0' && s1[i] <= '9'){
                printf("%02d:",s1[i] - '0');
                break;
            }
        }
    }
    for(int i = 0;i < r1.size() && i < r2.size();i++){
        if( r1[i] == r2[i] ){
            if((r1[i] >= 'a' && r1[i] <= 'z') || (r1[i] >= 'A' && r1[i] <= 'Z')){
                printf("%02d",i);
                break;
            }
        }
    }
    return 0;
}