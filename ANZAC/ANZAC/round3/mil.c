
#include <stdio.h>
#include <stdlib.h>



FILE* outputFile;

int main() {
    
    outputFile = fopen("in.txt","w");
    fprintf(outputFile,"%d",1000000); 
    int i;
    for( i = 0; i < 1000000; i++){
        fprintf(outputFile,"%d ", 1000);
    }

    fclose(outputFile);

    return 0;
}
