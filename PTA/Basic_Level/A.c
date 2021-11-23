#include <stdio.h>
void comp(int *a,int *b,int *c,int t)
{
	int d;
	for(int j=t-1;j>0;j--){
		for(int i=0;i<j;i++){
		    if(*(a+i)>*(a+i+1)){
		    	d=*(a+i);
		    	*(a+i)=*(a+i+1);
		    	*(a+i+1)=d;
			}
		}
	}
	*b=*(a+t-1);
	*c=*a;
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n],t;
	int max,min;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	t=sizeof(a)/sizeof(a[0]);
	comp(a,&max,&min,n);
	printf("max = %d,min = %d",max,min);
} 