#include<stdio.h>
#include<string.h>

int main(void)
{
    char s1[81],s2[81];
    gets(s1);
    gets(s2);
    char *p;
    while((p=strstr(s1,s2))!=NULL){
        *p='\0';
        strcat(s1,p+strlen(s2));
    }
    puts(s1);
	return 0;
}