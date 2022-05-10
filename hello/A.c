#include <stdio.h>
#include <string.h>
struct student {
	char name[20];
	double score[3], sum;
};
int main()
{
	void input(struct student stu[],int n);
	void swap(struct student stu[],int n);
	void print(struct student stu[],int n);
	int n;
	scanf("%d",&n);
	struct student stu[n];
	input(stu,n);
	swap(stu,n);
	print(stu,n);
	return 0;
}
void input(struct student stu[],int n)
{
	for(int i=0;i<n;i++){
		scanf("%s %lf %lf %lf",stu[i].name,&stu[i].score[0],
		&stu[i].score[1],&stu[i].score[2]);
		stu[i].sum=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];
	}
}
void swap(struct student stu[],int n)
{
	char a[20];
	int t;
	for(int i=n;i>1;i--){
		for(int j=0;j<i-1;j++){
			if(stu[j].sum>stu[j+1].sum){
				strcpy(a,stu[j].name);
				strcpy(stu[j].name,stu[j+1].name);
				strcpy(stu[j+1].name,a);

				t=stu[j].score[0];
				stu[j].score[0]=stu[j+1].score[0];
				stu[j+1].score[0]=t;

				t=stu[j].score[1];
				stu[j].score[1]=stu[j+1].score[1];
				stu[j+1].score[1]=t;

				t=stu[j].score[2];
				stu[j].score[2]=stu[j+1].score[2];
				stu[j+1].score[2]=t;

				t=stu[j].sum;
				stu[j].sum=stu[j+1].sum;
				stu[j+1].sum=t;
				
			}
		}
	}
}
void print(struct student stu[],int n)
{
	
	for(int i=n-1;i>=0;i--){
		printf("%s %.1lf %.1lf %.1lf %.1lf\n",stu[i].name,stu[i].score[0],stu[i].score[1],
		stu[i].score[2],stu[i].sum);
	}
}
