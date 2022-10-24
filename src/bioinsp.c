#include "bioinsp.h"

#define INFINITO 100000000

int bioinsp(Matrix matrix, int populationSz, int plato){
    int stop;
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