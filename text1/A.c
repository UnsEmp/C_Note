#include <stdio.h>
#define MAX 10010
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int arr[MAX], count[MAX], hash[MAX];
	for(int i = 0;i < n;i++) {
		int tmp;
		scanf("%d", &tmp);
		if(!hash[tmp]) {
			hash[tmp]++;
			arr[i] = tmp;
		}
		count[tmp]++;
	}
	for(int i = n - 1;i > 0;i--) {
		for(int j = 1;j <= i;j++) {
			if(arr[j - 1] < arr[j]) {
				int t = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = t;
			}
		}
	}
	// for(int i = 0;i < n;i++) printf("%d ",arr[i]);
	printf("%d", count[arr[k]]);
	return 0;
}