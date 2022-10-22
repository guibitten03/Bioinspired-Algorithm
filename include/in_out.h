#ifndef __IN_OUT__
#define __IN_OUT__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct args_t {
    char * filePath;
    char * type;
};

struct matrix{
    int** matrix;
    int len;
};

typedef struct args_t args;
typedef struct args_t * Args;

typedef struct matrix Matrix;

void argShowUsage(char *programName);
void argsParse(Args a, int argc, char **argv);
void deleteMatrix(Matrix *matrix);
Matrix createMatrix(FILE *inputFile, int matrixSize);
Matrix fileGetMatrix(int argc, char **argv);

#endif