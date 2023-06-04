#include "file.h"

#define BUFFER_LEN 5000

void argsParse(Args a, int argc, char ** argv){
    if (argc < 6){
        argShowUsage(argv[0]);
        exit(EXIT_FAILURE);
    }

    a->filePath = argv[1];
    a->type = argv[2];
}

void argShowUsage(char * programName){
    fprintf(stderr, "Usage: %s <filePath> <fileType> <populationSize> <platô> <mutation>\n\n", programName);
    fprintf(stderr, "File Types: <lau> or <sgb>\n\n");
    fprintf(stderr, "Mutation: In percent <0%% - 100%%>\n\n");
    
}

void deleteMatrix(Matrix * matrix){

    for(int c=0; c<matrix->len; c++){
        free(matrix->matrix[c]);
    }
    free(matrix->matrix);
}

Matrix fileGetMatrix(int argc, char ** argv){

    #ifdef printSteps
    printf("Getting Matrix...\n");
    #endif 

    args arguments;
    Matrix matrix;
    FILE * inputFile;
    int matrixSize; 

    argsParse(&arguments, argc, argv);

    inputFile = fopen(arguments.filePath, "r");
    if (NULL == inputFile){
        fprintf(stderr, "Could not open file: %s\n", arguments.filePath);
        matrix.matrix = NULL;
        matrix.len = 0;
        return matrix; 
    }

    if (!strcmp(arguments.type, "lau")){ 
        matrixSize = 15; 
        matrix = createMatrix(inputFile, matrixSize);
    }
    if (!strcmp(arguments.type, "sgb")) {
        matrixSize = 128; 
        matrix = createMatrix(inputFile, matrixSize);
    }
    if (!strcmp(arguments.type, "crt")) {
        matrix = createMatrixToCartesian(inputFile);
    }


    fclose(inputFile);

    return matrix;

}

Matrix createMatrix(FILE * inputFile, int matrixSize){
    Matrix matrix;
    char delimit[]= " \t\r\n\v\f";
    char buffer[BUFFER_LEN];
    char *aux;
    int x,y;
    
    matrix.matrix = (float**)malloc(matrixSize*sizeof(float**));
    for(int c=0; c<matrixSize; c++){
        matrix.matrix[c] = (float*)malloc(matrixSize*sizeof(float));
        
    }
    // matrix.matrix = (int**)malloc(matrixSize*sizeof(int**));
    // for(int c=0; c<matrixSize; c++){
    //     matrix.matrix[c] = (int*)malloc(matrixSize*sizeof(int));
        
    // }

    matrix.len = matrixSize;

    x = 0;
    while(x<matrix.len){

        fgets(buffer, sizeof(buffer), inputFile);
        if (buffer[0] == '#'){
            continue;
        }
        
        y = 0;
        aux = strtok(buffer, delimit);
        while(aux != NULL){
            
            matrix.matrix[x][y] = atoi(aux);

            aux = strtok(NULL, delimit);
            y++;
        }
        x++;
    }

    return matrix;
}

Matrix createMatrixToCartesian(FILE * inputFile){
    Matrix matrix;
    Point *points;
    // char delimit[]= " \t\r\n\v\f";
    // char buffer[BUFFER_LEN];
    // char *aux;
    int matrixSize;
    // int x,y;

    fscanf(inputFile,"%d", &matrixSize);
    
    points = (Point*)malloc(matrixSize*sizeof(Point));

    for(int c=0; c<matrixSize; c++){ fscanf(inputFile, "%d %d", &points[c].x, &points[c].y); }

    matrix.matrix = (float**)malloc(matrixSize*sizeof(float**));
    for(int c=0; c<matrixSize; c++){
        matrix.matrix[c] = (float*)malloc(matrixSize*sizeof(float));
        
    }

    matrix.len = matrixSize;

    for(int c=0; c<matrixSize; c++){
        for(int d=0; d<matrixSize; d++){
            if(c==d){ continue; }
            matrix.matrix[c][d] = cartesianDistance(points[c], points[d]);
        }
    }

    free(points);

    return matrix;
}

float cartesianDistance(Point a, Point b){
    return sqrt(pow((a.y - b.y), 2)+pow((a.x - b.x), 2));
}