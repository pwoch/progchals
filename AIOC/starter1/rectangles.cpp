#include <stdio.h>
#include <stdlib.h>

#define TEST_COUNT 5
bool isLeftCornerInsideRectangle(int pointX, int pointY, int rectX1, int rectY1, 
        int rectX2, int rectY2);

bool isRightCornerInsideRect(int pointX, int pointY, int rectX2, int rectY2); 

bool isRightCornerBoundedByRightEdgeOfRect(int pointX, int pointY, int rectX2, int rectY2);

bool isRightCornerBoundedByTopEdgeOfRect(int pointX, int pointY, int rectX2, int rectY2);

bool equalPoints(int x1,int y1 ,int x2,int y2);

FILE* inputFile;
FILE* outputFile;

int main() {

    int ax1, ay1, ax2, ay2;
    int bx1, by1, bx2, by2;
    int areaA, areaB, areaShared, result;

    inputFile = fopen("bendin.txt","r");
    outputFile = fopen("bendout.txt","w");

    while( counter < TEST_COUNT) { 
        fscanf(inputFile,"%d %d %d %d", &ax1, &ay1, &ax2, &ay2);
        fscanf(inputFile,"%d %d %d %d", &bx1, &by1, &bx2, &by2);

        areaA = (ax2 - ax1)*(ay2 - ay1);
        areaB = (bx2 - bx1)*(by2 - by1);
        areaShared = 0;

        //Check if RectB is partly or wholly inside rectA
        if( isLeftCornerInsideRectangle(bx1, by1, ax1, ay1, ax2, ay2)) {

            if ( isRightCornerInsideRect( bx2, by2, ax2, ay2)) {
                //RectangleB is contained inside RectangleA
                areaB = 0;

            } else if( isRightCornerBoundedByRightEdgeOfRect( bx2, by2, ax2, ay2)) {
                areaShared = (ax2 - bx1)*(ay2 - by1);

            } else if( isRightCornerBoundedByTopEdgeOfRect( bx2, by2, ax2, ay2)) {
                areaShared = (ax2 - bx1)*(ay2 - by1);

            } else {
                // The bottom left corner of RectB is inside RectA
                // but the top right corner of B has x,y co-ordinates which
                // are greater than or equal to the x,y co-ordinates of
                // the top right corner of A.

                if( equalPoints(ax1, ay1, bx1, by2)){
                    //if A and B have same left corner co-ordinate
                    //then A is contained in B
                    areaA = 0;

                } else {
                    areaShared = (ax2 - bx1)*(ay2 - by1);

                }

            }

            //Check if RectA is partly or wholly inside rectB
        } else if( isLeftCornerInsideRectangle(ax1, ay1, bx1, by1, bx2, by2)) {

            if ( isRightCornerInsideRect( ax2, ay2, bx2, by2)) {
                //RectangleA is contained inside RectangleB
                areaA = 0;

            } else if( isRightCornerBoundedByRightEdgeOfRect( ax2, ay2, bx2, by2)) {
                areaShared = (bx2 - ax1)*(by2 - ay1);

            } else if( isRightCornerBoundedByTopEdgeOfRect( ax2, ay2, bx2, by2)) {
                areaShared = (bx2 - ax1)*(by2 - ay1);

            } else {
                // The bottom left corner of RectA is inside RectB
                // but the top right corner of A has greater x,y co-ordinates
                // than the top right corner of B.
                if( equalPoints(ax1, ay1, bx1, by1)){
                    areaB = 0;

                } else {
                    areaShared = (bx2 - ax1)*(by2 - ay1);
                }
            }

        } else {
            //Rectangles are not overlapping

        }

        result = areaA + areaB - areaShared;

        counter++;
        fprintf(outputFile,"Test %d: %d\n",counter, result);
        
    }
        fclose(outputFile);
        fclose(inputFile);

        return EXIT_SUCCESS;
    }

    bool isLeftCornerInsideRectangle(int pointX, int pointY, int rectX1, int rectY1, 
            int rectX2, int rectY2) {
        bool result;

        result = ((rectX1 <= pointX) && (pointX <= rectX2)) && 
            ((rectY1 <= pointY) && (pointY <= rectY2));

        return result;
    }

    bool isRightCornerInsideRect(int pointX, int pointY, int rectX2, int rectY2){
        bool result;

        result = ((pointX < rectX2) && (pointY < rectY2));

        return result;
    }

    bool isRightCornerBoundedByRightEdgeOfRect(int pointX, int pointY, int rectX2, int rectY2) {
        bool result;

        result = ((pointX > rectX2) && (pointY == rectY2));

        return result;
    }

    bool isRightCornerBoundedByTopEdgeOfRect(int pointX, int pointY, int rectX2, int rectY2) {
        bool result;

        result = ((pointY  > rectY2) && (pointX == rectX2));

        return result;
    }

    bool equalPoints(int x1, int y1, int x2, int y2) {
        bool result;

        result = ((x1 == x2) && (y1 == y2));

        return result;
    }

