#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream outfile;
    outfile.open("Data.txt", ios::binary | ios::app | ios::in | ios::out);
    outfile << 5000 << endl;
    int tmp = 1;
    for(int i = 1;i <= 5000;i++) {
        outfile << 2 << " " << i << endl;
        for(int j = 0;j < i;j++) {
            outfile << tmp;
            if(j != i - 1) outfile << " ";
        }
        outfile << endl;
        if(i % 50 == 0) tmp++;
    }
    outfile.close();
    cout << "生成成功" << endl;
    return 0;
}