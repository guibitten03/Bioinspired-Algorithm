#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bioinsp.h"

int main(int argc, char ** argv){

    Matrix matrix = fileGetMatrix(argc, argv);

    int dist = bioinsp(matrix, 200, 100);
    printf("%d\n", dist);

    deleteMatrix(&matrix);

}
