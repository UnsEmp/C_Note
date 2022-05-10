#include <stdio.h>
#include <string.h>
#define MAX 255

char word[MAX], ch;

void reverse(char word[], int l, int r) {
    while(l < r) {
        char t = word[l];
        word[l] = word[r];
        word[r] = t;
        l ++;
        r --;
    }
}

int main() {
    scanf("%s %c", word, &ch);
    // getchar();
    // scanf("%c", &ch);
    for(int i = 0;i < strlen(word);i++) {
        if(word[i] == ch) {
            reverse(word, 0, i);
            break;
        }
    }
    printf("%s", word);
}