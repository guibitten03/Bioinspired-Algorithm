#ifndef __FILE_H__
#define __FILE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct args_t {
    char * filePath;
    char * type;
};

struct matrix{
    float** matrix;
    int len;
};

struct point{
    int x;
    int y;
};

typedef struct args_t args;
typedef struct args_t * Args;

typedef struct matrix Matrix;

typedef struct point Point;

void argShowUsage(char *programName);
void argsParse(Args a, int argc, char **argv);
void deleteMatrix(Matrix *matrix);
Matrix createMatrix(FILE *inputFile, int matrixSize);
Matrix createMatrixToCartesian(FILE * inputFile);
Matrix fileGetMatrix(int argc, char **argv);
float cartesianDistance(Point a, Point b);

#endif