#ifndef __BIOINSP_H__
#define __BIOINSP_H__

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"


typedef struct individuo_t Individuo;
typedef struct population_t Population;

struct individuo_t{
    int traitsSz;
    int * traits;
    int dist;
};

struct population_t{
    Individuo * population;
    Matrix matrix;
    int populationSz;
    Individuo bestIndividuo;
};

int bioinsp(Matrix matrix, int populationSz, int plato);
Population createPopulation(Matrix matrix, int populationSz);
Individuo createIndividuo(int individuoSz);
void darwinism(Population * population);
Individuo crossover(Individuo father, Individuo mother, int order);
void mutation(Individuo* individuo, int mutationP);

#endif