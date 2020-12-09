#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "matrix.h"



/* generate random matrix*/
float** generateMatrix(int n){
    int i,j;
 
     
    float a;   
    float **matrix = (float **)malloc(n*sizeof(float *));
    for (i = 0; i<n; i++) {
        matrix[i] = (float *)malloc(n*sizeof(float));
    }
   
    
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
        	a = (float)rand()/((float)RAND_MAX/2.0);
             (*(matrix[i]+j)) = a;
             }
    }
  
    return matrix;
}

//2) ikj form:
float **ikjForm(float **matrix1, float **matrix2, float **matrix3 ,int n){
      int i,j,k;
      clock_t begin = clock();
    for (i = 0; i < n; i++) {
            for (k = 0; k < n; k++) {
                for (j = 0; j < n; j++)
                    matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
                   
            } 
    }
     clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Multiplication in ikj form done in %f seconds.\n", time_spent);
    return matrix3;
    }
    
        
//3) jik form:
float **jikForm(float **matrix1, float **matrix2, float **matrix3 ,int n){
int i,j,k;
clock_t begin = clock();
     for (j = 0; j < n; j++) {
            for (i = 0; i < n; i++) {
                for (k = 0; k < n; k++)
                    matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
 }
 }
 clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Multiplication in jik form done in %f seconds.\n", time_spent);
    return matrix3;
 }
        
//4) jki form:    
float **jkiForm(float **matrix1, float **matrix2, float **matrix3 ,int n){
int i,j,k;
clock_t begin = clock();
     for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                for (i = 0; i < n; i++)
                    matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
         clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Multiplication in jki form done in %f seconds.\n", time_spent);
         return matrix3;
         }

//5) kij form:
 float **kijForm(float **matrix1, float **matrix2, float **matrix3 ,int n){
int i,j,k;
clock_t begin = clock();
     for (k = 0; k < n; k++) {
            for (i = 0; i < n; i++) {
                for (j = 0; j< n; j++)
                   matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }   
        }
        clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Multiplication in kij form done in %f seconds.\n", time_spent);
  	  return matrix3;
        }
  
//6) kji form:

float **kjiForm(float **matrix1, float **matrix2, float **matrix3 ,int n){
int i,j,k;
clock_t begin = clock();
    for (k = 0; k < n; k++) {
            for (j = 0; j < n; j++) {
                for (i = 0; i < n; i++)
                    matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
        clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Multiplication in kji form done in %f seconds.\n", time_spent);
    return matrix3;
}       
        
    
    
    
float** matrixMatrixMultiply(float **matrix1, float **matrix2, int n){
    int i, j,k;
    // create a new matrix
    float **newMatrix = (float **)malloc(n*sizeof(float *));
    for (i = 0; i<n; i++) {
        newMatrix[i] = (float *)malloc(n*sizeof(float));
    }
    
    //1) ijk form:
    clock_t begin = clock();
    for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++){
               for (k = 0; k < n; k++)
                    newMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Multiplication in ijk form done in %f seconds.\n", time_spent);
    
    
    
    /*multiply for all forms*/

     //2) ikj form
    ikjForm(matrix1,matrix2,newMatrix ,n);
    
   //3) jik form
    jikForm(matrix1,matrix2,newMatrix ,n);
    
    //4)jki form
    jkiForm(matrix1,matrix2,newMatrix ,n);
    
    //5) kij form
    kijForm(matrix1,matrix2,newMatrix ,n);
    
    //6) kji form
    kjiForm(matrix1,matrix2,newMatrix ,n);
    
   
  
  
         return newMatrix;
}


 

