#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int row = 3;
	while((2 * row * row - 2 * row + 1) <= n) row++;
	row--;
	printf("%d\n", n % (2 * row * row - 2 * row + 1));
	for(int i = 1;i <= row;i++) {
		for(int j = 0;j < 2 * (row - i + 1) - 2;j++) {
			printf(" ");
		}
		for(int k = 0;k < 2 * i - 1;k++) {
			printf("*");
			if(k != 2 * i - 1) printf(" ");
		}
		printf("\n");
	}
	for(int i = row - 1;i >= 1;i--) {
		for(int j = 0;j < 2 * (row - i + 1) - 2;j++) {
			printf(" ");
		}
		for(int k = 0;k < 2 * i - 1;k++) {
			printf("*");
			if(k != 2 * i - 1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}