#include <stdio.h>
int f(char a[],int i,int j)
{
	int t=0;
	while(i){
		a[t]='0'+i%j;
		if(i%j==10){
			a[t]='A';
		}
		if(i%j==11){
			a[t]='B';
		}
		t++;
		i/=12;
	}
	return t;
}
int main()
{
	int m,k;
	char a[100];
	scanf("%d %d",&m,&k);
	for(int i=f(a,m,k)-1;i>=0;i--){
		printf("%c",*(a+i));
	}
	return 0;
}