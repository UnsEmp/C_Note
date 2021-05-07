#include <cstdio>
#include <cstring>
struct student
{
    char name[20];
    int a;
    int b;
    int c;
};
int main()
{
 //   int char a[20]={"bing"};
    struct student stu_1;
    struct student *p=&stu_1;
   // strcpy(p->name,"bingbing");
  //  scanf("%s",p->name);
  stu_1.name="bing";
    p->a=90;
    p->b=85;
    p->c=87;
    int sum=0;
    sum=p->a+p->b+p->c;
    printf("姓名：\n%s\n",p->name);
    printf("%d %d %d\n",p->a,p->b,p->c);
    printf("%d",sum);

}
