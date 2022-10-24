#include "bioinsp.h"

#define INFINITO 100000000

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
    population.bestIndividuo.individuo = NULL;
    population.population = (Individuo*)malloc(populationSz*sizeof(Individuo));

    for(int c=0; c<populationSz; c++){
        population.population[c] = createIndividuo(population.matrix.len);
    }


    return population;
}


