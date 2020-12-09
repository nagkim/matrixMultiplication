#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "matrix.h"



int main(int argc, char **argv){
    
    int n;
    printf("Enter size of matrix");
    scanf("%d[^\n]", &n);
    printf("MATRIX %d x %d \n", n,n);
   float **matrix1= generateMatrix(n); 
   float **matrix2 = generateMatrix(n);
    
 matrixMatrixMultiply(matrix1, matrix2, n);
    
 
}
