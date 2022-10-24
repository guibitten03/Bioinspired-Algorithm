#ifndef __BIOINSP_H__
#define __BIOINSP_H__

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "in_out.h"
#include "evaluation.h"

struct individuo_t{
    int * individuo;
    int dist;
};

struct population_t{
    Individuo *population;
    Matrix matrix;
    int populationSz;
    Individuo bestIndividuo;
};

typedef struct individuo_t Individuo;
typedef struct population_t Population;

Population createPopulation(Matrix matrix, int populationSz);
Individuo createIndividuo(int individuoSz);
void crossover(Population* population);
void Mutation(Individuo* individuo);
int bioinsp(Matrix matrix, int populationSz, int plato);

#endif