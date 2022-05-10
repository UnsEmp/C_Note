#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    int ru = 0, to = 0, count = 0;
    while(t > 0) {
        ru += 9;
        to += 3;
        t--;
        count++;
        if(count % 10 == 0) {
            if(ru > to) {
                to += 90;
                t -= 30;
            }
        }
    }
    to -= -t * 3;
    if(ru > to) printf("^_^ %d", ru);
    else if(ru < to) printf("@_@ %d", to);
    else printf("-_- %d", ru);
    return 0;
}