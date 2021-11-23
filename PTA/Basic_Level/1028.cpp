#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int n;
    int count = 0;
    cin>>n;
    char Max[20] = "1814/09/05";
    char Min[20] = "2014/09/07";
    char old[20],young[20];
    for ( int i = 0 ; i < n ; i++){
        char name[10],birthday[20];
        scanf("%s %s",name,birthday); 
        if ((strcmp(birthday,"1814/09/05") > 0) && ( strcmp("2014/09/07",birthday) > 0)){
            count++;
            if (strcmp(birthday,Max) > 0){
                strcpy(Max,birthday);
                strcpy(old,name);
            }
            if ( strcmp(Min,birthday) > 0){
                strcpy(Min,birthday);
                strcpy(young,name);
            }
        }
    } 
    if ( count > 0){
        cout<<count<<" "<<young<<" "<<old;
    }
    else{
        cout<<0;
    }
    return 0;
}