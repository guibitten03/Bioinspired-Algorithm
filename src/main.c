#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"

struct args_t {
    char * filePath;
    char * type;
};

typedef struct args_t args;
typedef struct args_t * Args;

void argShowUsage(char * programName);
void argsParse(Args a, int argc, char ** argv);

void fileGetMatrix(FILE * f, int * matrix, int matrixSz);

int main(int argc, char ** argv){
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

    int matrix[matrixSize][matrixSize];

    fileGetMatrix(inputFile, &matrix, matrixSize);

}

void argsParse(Args a, int argc, char ** argv){
    if (argc < 3){
        argShowUsage(argv[0]);
        exit(EXIT_FAILURE);
    }

    a->filePath = argv[1];
    a->type = argv[2];
}

void argShowUsage(char * programName){
    fprintf(stderr, "Usage: %s <filePath> <fileType>\n\n", programName);
    fprintf(stderr, "File Types: <lau> or <sgb>\n\n");
    
}

void fileGetMatrix(FILE * f, int * matrix, int matrixSz){
    char buffer[200];

    int hasInput = 1;
    int count = 0;
    while(hasInput){
        fgets(buffer, sizeof(buffer), f);
        if (buffer[0] == '#'){
            
        }
        break;
    }

}