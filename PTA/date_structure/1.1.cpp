#include <cstdio>
int main()
{
	int k,temp;
	scanf("%d",&k);
	int thissum = 0,maxsum = 0;
	for(int i = 0;i < k;i++){
		scanf("%d",&temp);
		thissum += temp;
		if(thissum > maxsum){
			maxsum = thissum;
		}
		else if(thissum < 0){
			thissum = 0;
		}
	}
	if(maxsum < 0){
		printf("0");
	}
	else{
		printf("%d",maxsum);
	}
	return 0;
}