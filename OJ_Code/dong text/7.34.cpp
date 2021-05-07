#include <stdio.h>
typedef struct message
{
    char name[20];
    char birthday[20];
    char sex;
    char numbers[17];
    char phone[17];
}mess;
int main()
{
    int n;
    scanf("%d",&n);
    if(n>0){
            mess men[n];
        for(int i=0;i<n;i++){
            scanf("%s %s %c %s %s",men[i].name,men[i].birthday,
            &men[i].sex,men[i].numbers,men[i].phone);
        }
        int k;
        scanf("%d",&k);
        int a;
        for(int i=0;i<k;i++){
            scanf("%d",&a);
            if(a<n&&a>=0){
                printf("%s %s %s %c %s\n",men[a].name,men[a].numbers,men[a].phone,
                men[a].sex,men[a].birthday);
            }
            else{
                printf("Not Found\n");
            }
        }
    }
    return 0;

}