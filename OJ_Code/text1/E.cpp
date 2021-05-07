#include<stdio.h>
int main()
{
	char input, blank = ' ';
	int num_letter = 0;
	int flag=0;
	
	while((input = getchar()) != '.'){
		if(input != ' '){
			num_letter++;
		}
		else if(num_letter != 0){
			if(flag != 0){
				putchar(blank);
			}
			flag = 1;
			printf("%d",num_letter);
			num_letter = 0; 
		}
		else{
			continue;
		}
	}
	if(flag == 1&&num_letter != 0){
		putchar(blank);
	}
	if(num_letter){
		printf("%d",num_letter);
	}
	return 0;
 }