# matrix-multiplication
This program implements 3 functions, the first function mutliplyMatrices takes in two matrices with the number of rows and columns for each.
Using this information, the function I wrote multiplies the two matrices.

The second function multiplyMatricesPtr returns a pointer to a pointer of type double. This function employs the idea of dynamic memory allocation where
there is a dynamic matrix where every element in the array points to a row of the array, and all matrices are allocated on the heap using malloc. 

Finally, the last function transposeMatrixPtr again returns again returns a pointer to a pointer of type double. This time, the function takes in a 
dynamically allocated matrix with a number of rows and columns, and the function transposes the two matrices so that the elements are reflected across the diagonal
you can learn more about the idea here: https://en.wikipedia.org/wiki/Transpose
