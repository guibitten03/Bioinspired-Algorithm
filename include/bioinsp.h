#ifndef __BIOINSP_H__
#define __BIOINSP_H__

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "in_out.h"
#include "evaluation.h"

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

Population createPopulation(Matrix matrix, int populationSz);
Individuo createIndividuo(int individuoSz);
void crossover(Population* population, Individuo bestIndividuo);
void Mutation(Individuo* individuo, int mutationP);
int bioinsp(Matrix matrix, int populationSz, int plato);

#endif