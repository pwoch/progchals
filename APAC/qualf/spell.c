



#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {

    int i, g, t;
    int size;
    int answer;

    char *word = malloc(5);

    scanf("%d",&t);
    for( g = 0; g < t; g++) {
        scanf("%s", word);
        size = strlen(word);
        if( size == 1) {
            answer = 1;

        } else if( size == 2) { 
            if( word[0] == word[1]) {
                answer = 1;
            } else {
                answer = 4;
            }
            
        } else {
            if( word[0] == word[1]) { 
                answer = 1;
            }else {
                answer =2;
            }

            for( i = 1; i < size -1; i++) {
                if( word[i] == word[i-1]  && word[i] == word[i+1]) {
                    answer *= 1;
                } else if( word[i] == word[i-1] || word[i] == word[i+1]) {
                    answer *=2;
                } else {
                    answer *= 3;
                }
            }
            if( word[i-1] == word[i]) {
                answer*=1;
            } else {
                answer *=2;
            }
        }

        printf("Case #%d: %d\n", g+1, answer);
    }


    return 0;
}



