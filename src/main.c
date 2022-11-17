#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bioinsp.h"

int main(int argc, char ** argv){

    Matrix matrix = fileGetMatrix(argc, argv);
    
    int dist = bioinsp(matrix, atoi((argv[3])), atoi((argv[4])), atoi((argv[5])));
    printf("%d\n", dist);

    deleteMatrix(&matrix);

}
