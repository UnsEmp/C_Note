    #include <stdio.h>
    #include <string.h>
    int main()
    {
        char c;
        int count=0,cnt=0;
        while((c=getchar())!='.'){
            if(c==' '){
                if(count==0){
                    continue;
                }
                printf("%d",count);
                if(cnt==1){
                printf(" ");
                }
                cnt=0;
                count=0;
            }
            else{
                count++;
                cnt=1;
            }
        }
        if(count!=0){
            printf("%d",count);
        }
        return 0;
}
