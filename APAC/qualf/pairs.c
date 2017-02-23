
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 256    
#define SIZE 127
#define NO_ITEM -1

#define BLACK 100
#define WHITE 50

typedef struct _item{
    char key[LENGTH];
    int value;
}item;

char* dummy = "-1";

int hash( item it, int N);

int main()
{
    int T, t;
    scanf("%d", &T);
    for( t = 0; t < T; t++)
    {
        int N;
        scanf("%d",&N);

        item items[SIZE];
        int i;
        for( i = 0; i < 2*N; i++)
        {
            scanf("%s", items[i].key);
        }

        int colours[SIZE] = {0};
        colours[hash(items[0], SIZE)] = BLACK;

        int valid = 1;
        int colour = 0;
        int other = 0;
        for( i = 0; i < 2*N; i+=2)
        {
            //printf("Looking at %s and %s\n", items[i].key, items[i+1].key);
            colour = colours[hash(items[i],SIZE)];
            if( colour != 0) {
                other = (colour == BLACK) ? WHITE : BLACK;
                if( colours[hash(items[i+1], SIZE)] == colour) {
                    valid = 0;
                } else {
                    colours[hash(items[i+1], SIZE)] = other;
                }
            } else if( colours[hash(items[i+1], SIZE)] != 0) {
                colour = colours[hash(items[i+1], SIZE)];
                other = (colour == BLACK) ? WHITE : BLACK;
                if( colour != 0) {
                    other = (colour == BLACK) ? WHITE : BLACK;
                    if( colours[hash(items[i], SIZE)] == colour) {
                        valid = 0;
                    } else {
                        colours[hash(items[i], SIZE)] = other;
                    }
                }
            }
        }

       /* for( i = 0; i < 2*N; i++){
            item it = items[i];
            printf("Colour of %s is: %d\n", it.key, colours[hash(it, SIZE)]);
        }*/

        printf("Case #%d: ", t+1);
        if( valid == 0){
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}

int hash( item it, int N)
{
    int val = 0;
    char* tmp;
    for( tmp = it.key; *(tmp) != '\0'; tmp++){
        val += *tmp;
    }
    val = val % N;

    return val;
}



