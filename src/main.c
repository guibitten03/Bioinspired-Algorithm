#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "in_out.h"

int main(int argc, char ** argv){

    Matrix matrix = fileGetMatrix(argc, argv);

    int dist = bioinsp(matrix, 5, 5);
    printf("%d", dist);

    deleteMatrix(&matrix);

}
