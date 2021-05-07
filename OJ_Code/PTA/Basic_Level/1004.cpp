#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n,score;
    int max = -1,min = 101;
    string name,num;
    pair<string, string> worst;
    pair<string, string> best;
    cin >> n;
    while(n--){
        cin >> name >> num >> score;
        if(score > max){
            max = score;
            best.first = name;
            best.second = num;
        }
        if(score < min){
            min = score;
            worst.first = name;
            worst.second = num;
        }
    }
    cout << best.first << " " << best.second << endl;
    cout << worst.first << " " << worst.second << endl;
    return 0;
}