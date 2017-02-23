#include <stdio.h>
#include <stdlib.h>

FILE* inputFile;
FILE* outputFile;

int bigger( int a, int b) {
    return ( a > b) ? a : b;
}
int smaller( int a, int b) {
    return (a > b) ? b : a;
}

int main() {

    int ax1, ay1, ax2, ay2;
    int bx1, by1, bx2, by2;
    int areaA, areaB, areaShared, result;
    int rH, rW;

    inputFile = fopen("bendin.txt","r");
    outputFile = fopen("bendout.txt","w");

    int maxAX,minAX, maxAY, minAY;
    int maxBX, minBX, maxBY, minBY;
    int rX1, rY1, rX2, rY2;
    fscanf(inputFile,"%d %d %d %d", &ax1, &ay1, &ax2, &ay2);
    fscanf(inputFile,"%d %d %d %d", &bx1, &by1, &bx2, &by2);

    maxAX = bigger(ax1, ax2);
    minAX = smaller(ax1, ax2);
    maxAY = bigger(ay1, ay2);
    minAY = smaller(ay1, ay2);

    maxBX = bigger(bx1, bx2);
    minBX = smaller(bx1, bx2);
    maxBY = bigger(by1, by2);
    minBY = smaller(by1, by2);

    rX1 = (maxBX > maxAX) ? maxAX : maxBX;
    rY1 = (minBY < minAY) ? minAY : minBY;

    rX2 = (minBX < minAX) ? minAX : minBX;
    rY2 = (maxBY > maxAY) ? maxAY : maxBY;

    rW = rX1 - rX2;
    rH = rY2 - rY1;
    if( rW > 0 && rH > 0) {
        areaShared = rW*rH;
    } else {
        areaShared = 0;
    }
    areaA = (ax2 - ax1)*(ay2 - ay1);
    areaB = (bx2 - bx1)*(by2 - by1);

    fprintf(outputFile, "%d\n",areaA + areaB - areaShared);

    fclose(outputFile);
    fclose(inputFile);
    return 0;
}
