#include <stdio.h>
#define MAX 10010
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int arr[MAX] = {0}, count[MAX] = {0}, hash[MAX] = {0};
	for(int i = 0;i < n;i++) {
		int tmp;
		scanf("%d", &tmp);
		if(!hash[tmp]) {
			hash[tmp]++;
			arr[i] = tmp;
		}
		count[tmp]++; //某一个编号的帽子有多少个
	}
	for(int i = n - 1;i > 0;i--) {
		for(int j = 1;j <= i;j++) {
			if(arr[j - 1] < arr[j]) {
				int t = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = t;
			}
		}
	}s
	printf("%d", count[arr[k - 1]]);
	return 0;
}
