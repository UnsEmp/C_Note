#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	char arr[3] = {'1','2','3'};
	do{
		printf("%c%c%c\n",arr[0],arr[1],arr[2]);
	}while(next_permutation(arr,arr+3));
	return 0;
}