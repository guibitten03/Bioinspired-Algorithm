#include <stdbool.h>

#include "bioinsp.h"

#define INFINITO 100000000

int seed = 0;

int bioinsp(Matrix matrix, int populationSz, int plato){
    int stop = 0;
    int pastBestDist = INFINITO;
    Population population = createPopulation(matrix, populationSz);

    do{
        population.bestIndividuo = evaluation(&population);

        if(population.bestIndividuo.dist == pastBestDist){stop++;}
        else{
            stop = 0;
            pastBestDist = population.bestIndividuo.dist; 
        }

        crossover(&population);

    }while(stop > plato);

    return population.bestIndividuo.dist;
}

Population createPopulation(Matrix matrix, int populationSz){
    Population population;

    population.matrix = matrix;
    population.populationSz = populationSz;
    population.bestIndividuo.dist = INFINITO;
    population.bestIndividuo.traits = NULL;
    population.population = (Individuo*)malloc(populationSz*sizeof(Individuo));

    for(int c=0; c<populationSz; c++){
        population.population[c] = createIndividuo(population.matrix.len);
    }


    return population;
}

Individuo createIndividuo(int individuoSz){
    int random, modifi;

    Individuo individuo;
    individuo.dist = INFINITO;
    individuo.traits = (int*)malloc(individuoSz*sizeof(int));

    srand(time(NULL)+seed);
    for(int c=0; c<individuoSz; c++){
        random = rand()  % individuoSz;
        
        while (/* condition */)
        {
            /* code */
        }
        
    }

    return individuo;
}

void crossover(Population* population){
    bool par = population->populationSz % 2 == 0;
    for(int i = 0; i < (population->populationSz+1); i++){
        if(bool){
            
        }
    }
}