#include <stdio.h>
#include <stdlib.h>


int main() {

    FILE *inputFile;
    FILE *outputFile;

    inputFile = fopen("taktakin.txt","r");

    int init, total, i;
    
    fscanf(inputFile,"%d", &init);

    total = init;
    i = 0;
    while( total%11 != 1){
        total *=2;
        i++;
    }
    outputFile = fopen("taktakout.txt","w");
    fprintf(outputFile,"%d %d", i, total);

    fclose(outputFile);
    fclose(inputFile);

    return EXIT_SUCCESS;
}
