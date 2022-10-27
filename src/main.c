#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bioinsp.h"

int main(int argc, char ** argv){

    Matrix matrix = fileGetMatrix(argc, argv);

    printf("Passei;");
    int dist = bioinsp(matrix, 50, 5);
    printf("%d", dist);

    deleteMatrix(&matrix);

}
