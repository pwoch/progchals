import java.util.Arrays;
import java.lang.Object;
import java.io.*;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class watchmen {

    public static void main(String[] args){


        Scanner input = new Scanner(System.in);
        int max = input.nextInt();
        int[][] pos = new int[max][2];
        int[][] xSort = new int[max][2]; 
        int[][] ySort = new int[max][2];
        int[][] merge = new int[max][2];
        for(int i = 0; i < max ; i++){

            pos[i][0] = input.nextInt();
            pos[i][1] = input.nextInt();
        }


        BottomUpMergeSort(pos, merge, max, 0);
        

        for(int i = 0; i < max; i++) {

            System.out.println("(" + merge[i][0] + ", " + merge[i][1] + ")");

        }



    }



    // array A[] has the items to sort; array B[] is a work array
    static void BottomUpMergeSort(int[][] A,int[][] B,int n,int row ) {
        // Each 1-element run in A is already "sorted".
        // Make successively longer sorted runs of length 2, 4, 8, 16... until whole array is sorted.
        int otherRow = (row == 0) ? 1 : 0;

        for (int width = 1; width < n; width = 2 * width) {
            // Array A is full of runs of length width.
            for (int i = 0; i < n; i = i + 2 * width)
            {
                // Merge two runs: A[i:i+width-1] and A[i+width:i+2*width-1] to B[]
                // or copy A[i:n-1] to B[] ( if(i+width >= n) )
                BottomUpMerge(A, i, Math.min(i+width, n), Math.min(i+2*width, n), B,row, otherRow);
            }
            // Now work array B is full of runs of length 2*width.
            // Copy array B to array A for next iteration.
            // A more efficient implementation would swap the roles of A and B.
            CopyArray(B, A, n,  row,  otherRow);
            // Now array A is full of runs of length 2*width.
        }
    }

    //  Left run is A[iLeft :iRight-1].
    // Right run is A[iRight:iEnd-1  ].
    static void BottomUpMerge(int[][] A,int iLeft,int iRight, int iEnd, int[][] B, int row, int otherRow) {
        int left = iLeft;
        int right = iRight;
        // While there are elements in the left or right runs...

        for (int k = iLeft; k < iEnd; k++) {
            // If left run head exists and is <= existing right run head.
            if (left < iRight && (right >= iEnd || A[left][row] <= A[right][row])) {
                B[k][row] = A[left][row];
                B[k][otherRow] = A[left][otherRow];
                left++;

            } else {

                B[k][row] = A[right][row];
                B[k][otherRow] = A[right][otherRow];
                right++;    
            }
        } 
    }

    static void CopyArray(int[][] A, int[][]B,int n,int row, int otherRow) {

            for(int i = 0; i < n; i++) {
                A[i][row] = B[i][row];
                A[i][otherRow] = B[i][otherRow];
            }
        }


}










/*
        int counter = 0;
        int pairs = 0;
        int index = 0; 
        int[] number = new int[max+1];
        for(int i = 0; i < max - 1; i++){


            if( sortX[i] == sortX[i+1]){

                counter++;

                if( number[index] != sortX[i]) {
                    number[index] = sortX[i];
                }

            } else {

                index++;
                pairs += (counter > 1) ? (counter)*(counter-1)/2 : 1;

                if(counter == 0)
                    pairs = 0;

                else {

                    counter = 0;
                }
            }
        }

        System.out.println("Number of x-pairs: " + pairs);

        System.out.println("x co-ord pairs: " + Arrays.toString(number));

        
           for( int i = 0; i < max; i++){
           if(number[i] != 0){
           for(int i = 0; i < max; i++){
           if(

           pairs = 0;
           for(int i = 0; i < max - 1; i++){


           if( sortY[i] == sortY[i+1]){

           counter++;
           } else {

           pairs += (counter > 1) ? (counter)*(counter-1)/2 : 1;

           if(counter == 0)
           pairs = 0;
           else{
           counter = 0;
           }
           }
           }

           System.out.println("Number of y-pairs: " + pairs);
         */
