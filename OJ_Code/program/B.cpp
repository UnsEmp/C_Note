#include <stdio.h>
#include <string.h>

int Cac(int a,int b,char ch)
{
	int temp;
	switch(ch){
		case '+':temp = a + b;break;
		case '-':temp = a - b;break;
		case '*':temp = a * b;break;
		case '/':temp = a / b;break;
	}
    return temp;
}

int main()
{
	printf("输入数\n");
	printf("例如13*8\n");
	int a,b,temp,sum = 0;
	bool flag = true;
	char ch;
	char arr[10];
	gets(arr);
	while(strcmp(arr,"exit") != 0){
		for(int i = 0;i < strlen(arr);i++){
			if(arr[i] >= 48 && arr[i] <= 57){
				temp = (arr[i] - '0');
				sum = (sum * 10) + temp;
			}
			else if(arr[i] == ' '){
				flag = false;
				break;
			}
			else{
				ch = arr[i];
				a = sum;
				sum = 0;
			}
		}
		b = sum;
		sum = 0;
		if(flag){
			printf("%d%c%d=%d\n",a,ch,b,Cac(a,b,ch));
		}
		else{
			printf("输入错误\n");
		}
		gets(arr);
	}
	return 0;
}