// matrix-multiplication <Project2.cpp>
// EE 312 Project 2 submission by
// Abhishek Rao
// amr7999
// Slip days used: <0>
// Fall 2021
// Include the contents of this file at the top of every file that you submit, replacing the fields within <>.  Do not keep the <>.


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "MatrixMultiply.h"
//ccc
void multiplyMatrices(
        double a[],
        const uint32_t a_rows,
        const uint32_t a_cols,
        double b[],
        const uint32_t b_cols,
        double c[]) {
    //start
    int space = a_rows*b_cols;
    for(int x = 0; x < space; x++){
        c[x] = 0;
    }
    int colBn = b_cols;
    int condo;
    for (int i = 0; i < a_rows; i++) {
        for (int colCount = 0; colCount < colBn; colCount++) {
            if(colCount == 0){
                condo = 0;
            } else{condo = 1;}
            for (int j = 0; j < a_cols; j++) {
                c[(i*colBn) + (colCount*condo)] += a[(i*a_cols) + j] * b[(j*b_cols) + colCount];
            }
        }
    }
    /*printf("\n");
    for(int i = 0; i < a_rows; i++){
        for(int j = 0; j < b_cols; j++){
            printf("%d ,", c[i*a_rows+j]);
        }
        printf("\n");
    }*/
}



    // https://en.wikipedia.org/wiki/Row-_and_column-major_order

double** multiplyMatricesPtr(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols,
        double** b,
        const uint32_t b_cols) {
    double** c = (double**)malloc(a_rows*sizeof(double*));
    for(int i=0; i<a_rows; i++){
        double* pointer1 = (double*)malloc(a_cols*sizeof(double));
        c[i] = pointer1;
    }
    //old stuff
    for (int i = 0; i < a_rows; i++){
        for (int j = 0; j < b_cols; j++){
            c[i][j] = 0;
        }
    }
    for (int i = 0; i < a_rows; i++){
        for (int j = 0; j < b_cols; j++) {
            for(int k = 0; k < a_cols; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
    //free stuff right?
}

// https://en.wikipedia.org/wiki/Transpose
double** transposeMatrix(
         double** a,
         const uint32_t a_rows,
         const uint32_t a_cols) {
    //dynamic allocation here too but be careful - rows and columns swap
    double** c = (double**)malloc(a_cols*sizeof(double*));
    for(int i=0; i<a_cols; i++){
        double* pointer1 = (double*)malloc(a_rows*sizeof(double));
        c[i] = pointer1;
    }

    for (int i = 0; i < a_rows; i++){
        for (int j = 0; j < a_cols; j++){
            c[j][i] = a[i][j];
        }
    }
    return c;
}
