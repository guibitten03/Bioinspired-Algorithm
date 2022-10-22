#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "in_out.h"

int main(int argc, char ** argv){

    Matrix matrix = fileGetMatrix(argc, argv);

    for(int i=0; i<matrix.len; i++){
        for(int j=0; j<matrix.len; j++){
            printf("%d ", matrix.matrix[i][j]);
        }
        printf("\n");
    }

    deleteMatrix(&matrix);

    /*
    args arguments;

    argsParse(&arguments, argc, argv);

    FILE * inputFile = fopen(arguments.filePath, "r");
    if (NULL == inputFile){
        fprintf(stderr, "Could not open file: %s\n", arguments.filePath);
        return EXIT_FAILURE;
    }

    int matrixSize; 
    if (!strcmp(arguments.type, "lau")){ matrixSize = 15; }
    if (!strcmp(arguments.type, "sgb")) { matrixSize = 128; }


    int** matrix = (int**)malloc(matrixSize*sizeof(int**));
    for(int c=0; c<matrixSize; c++){
        matrix[c] = (int*)malloc(matrixSize*sizeof(int*));
    }

    fileGetMatrix(inputFile, matrix, matrixSize);

    deleteMatrix(matrix, matrixSize);

    fclose(inputFile);
    */

}
