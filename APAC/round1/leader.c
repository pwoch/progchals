


#include <stdio.h>
#include <stdlib.h>



int main() {

    int t, T;

        
    //array representing characters in the alphabet
    char a[27];
    char c;
    char name[21];
    char word[21];
    int max = 0;
    int size = 0;


    //Number of test cases
    scanf("%d", &T);
    for( t = 0; t < T; t++) {

        int i, n, N, j;

        for( n = 0; n < 21; n++) {
            word[n] = 0;
        }



        //Number of inputs per test case
        scanf("%d\n", &N);
        max = 0;

        for( i = 0; i < N; i++) {

            // Clear the alphabet and name array;
            for( n = 0; n < 21; n++){
                name[n] = 0;
            }
            for( n = 0; n < 27; n++){
                a[n] = 0;
            }

            size = 0;
            n = 0;
            scanf("%c", &c);
            while( c != '\n') {

                name[n] = c;
                if( c != ' ' && a[c-'A'] == 0) {
                    a[ c-'A']++;
                    size++;
                }
                scanf("%c",&c);
                n++;
            }
            //printf("Word: %s\t\t Size: %d\n", name, size);

            if( size > max || (size == max && strcmp(word, name) == 1)) {
                max = size;
                //store the word with most distinct letters
                for( j = 0; j < n; j++) {
                    word[j] = name[j];
                }
                word[j] = '\0';
            } 
        }
        printf("Case #%d: %s\n", t+1, word);
    }


    return EXIT_SUCCESS;
}
