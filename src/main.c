#include <stdio.h>
#include <stdlib.h>


struct args_t {
    char * filePath;
};

typedef struct args_t args;
typedef struct args_t * Args;

void argShowUsage(char * programName);
void argsParse(Args a, int argc, char ** argv);

int main(int argc, char ** argv){
    args arguments;

    argsParse(&arguments, argc, argv);

    FILE * inputFile = fopen(arguments.filePath, "r");
    if (NULL == inputFile){
        fprintf(stderr, "Could not open file: %s\n", arguments.filePath);
        return EXIT_FAILURE;
    }

}

void argsParse(Args a, int argc, char ** argv){
    if (argc < 2){
        argShowUsage(argv[0]);
        exit(EXIT_FAILURE);
    }

    a->filePath = argv[1];
}

void argShowUsage(char * programName){
    fprintf(stderr, "Usage: %s <filePath>\n\n", programName);
}