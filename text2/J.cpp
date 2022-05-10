#include <iostream>
#include <string>
#include <time.h>
using namespace std;
clock_t start,stop;
int gcd(int a,int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
    start = clock();
	int a = 12,b = 24,temp;
	for(int i = 0;i < 1000000;i++){
        temp = gcd(a,b);
    }
    stop = clock();
	cout << (stop - start); 
	return 0;
}