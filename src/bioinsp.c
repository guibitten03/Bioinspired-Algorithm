#include <stdbool.h>
#include "evaluation.h"
#include "bioinsp.h"

#define INFINITO 10000000
//#define printSteps

#define PUT_ON 1
#define N_PUT_ON 0

Individuo crossing_parse(Individuo firstParent, Individuo secondParent, int fIndex, int sIndex);

int bioinsp(Matrix matrix, int populationSz, int plato, int mutationP){

    #ifdef printSteps
    printf("Population is beeing created...\n");
    #endif

    int stop = 0;
    int pastBestDist = INFINITO;
    Population population = createPopulation(matrix, populationSz);
    int generation = 1;

    do{
        #ifdef printSteps
        printf("Generation %d in process...\n", generation);
        #endif

        evaluation(&population);

        if(population.bestIndividuo.dist == pastBestDist){ stop++; }
        else{
            stop = 0;
            pastBestDist = population.bestIndividuo.dist; 
        }

        #ifdef printSteps
        printf("Applying darwinism...\n");
        #endif

        if(stop == plato/2){
            darwinism(&population, 2*mutationP);      
        }
        else{
            darwinism(&population, mutationP);
        }

        generation++;

    }while(stop < plato);

    destroyPopulation(&population);

    return population.bestIndividuo.dist;
}

Population createPopulation(Matrix matrix, int populationSz){
    Population population;
    
    population.matrix = matrix;
    population.populationSz = populationSz;

    population.bestIndividuo.dist = INFINITO;
    population.bestIndividuo.traits = (int*)malloc(population.matrix.len*sizeof(int));
    population.bestIndividuo.traitsSz = population.matrix.len;
    population.population = (Individuo*)malloc(populationSz*sizeof(Individuo));

    for(int c = 0; c < populationSz; c++){
        population.population[c] = createIndividuo(population.matrix.len);

    }

    return population;
}

Individuo createIndividuo(int individuoSz){
    int random, modifi;

    Individuo individuo;
    individuo.dist = INFINITO;
    individuo.traits = (int*)malloc(individuoSz*sizeof(int));
    individuo.traitsSz = individuoSz;

    srand(microseg());

    for(int c=0; c<individuoSz; c++){
        random = rand()  % individuoSz;
        
        modifi = 1;
        while (modifi){
            modifi = 0;
            for(int i=0; i<c; i++){
                if(individuo.traits[i]==random){
                    modifi = 1;
                    random = rand()  % individuoSz;
                    break;
                }
            }
            
        }
        individuo.traits[c] = random;
    }

    return individuo;
}

void destroyIndividuo(Individuo * i){
    free(i->traits);
}

void destroyPopulation(Population * pop){
    for(int i = 0; i < pop->populationSz; i++){
        destroyIndividuo(&pop->population[i]);
    }
    destroyIndividuo(&pop->bestIndividuo);
    free(pop->population);
}

void mutation(Individuo * individuo, int mutationP){
    int random1, random2, aux;
    
    srand(microseg());
    for(int c=0; c<individuo->traitsSz; c++){
        random1 = (rand()%100);

        if(random1<=mutationP){
            random2 = rand() % individuo->traitsSz;

            aux = individuo->traits[c];
            individuo->traits[c] = individuo->traits[random2];
            individuo->traits[random2] = aux;
        }
    }
}

Individuo crossing_parse(Individuo firstParent, Individuo secondParent, int sIndex, int fIndex){
    int traits = firstParent.traitsSz;

    int strip = (fIndex - sIndex) + 1;


    Individuo child = createIndividuo(traits);


    for(int i = 0; i < strip; i++){ 
        child.traits[i + sIndex] = secondParent.traits[i + sIndex];
    }


    int count = fIndex + 1;
    int index = fIndex + 1;
    while(count != sIndex){
        int inStrip = 0;
        for(int i = 0; i < strip; i++){ 
            if(child.traits[i + sIndex] == firstParent.traits[index]){
                index = (index + 1) % traits;
                inStrip = 1;
                break;
            }
        }
        if(inStrip){ continue; }

        child.traits[count] = firstParent.traits[index];
        count = (count + 1) % traits;
        index = (index + 1) % traits;
    }

    return child;
}

Individuo crossover(Individuo father, Individuo mother, int order, int sIndex, int fIndex){
    if(order == 0){
        return crossing_parse(father, mother, sIndex, fIndex);
    }else{
        return crossing_parse(mother, father, sIndex, fIndex);
    }
}

void darwinism(Population * population, int mutationP){
    Individuo newPopulation[population->populationSz];

    #ifdef printSteps
    printf("Selecting best individuals...\n");
    #endif

    for(int i = 0; i < population->populationSz; i++){
        newPopulation->traitsSz = population->matrix.len;
        newPopulation[i].traits = NULL;
        newPopulation[i] = selection_in_4(population);
    }

    #ifdef printSteps
    printf("Doing the crossover...\n");
    #endif

    for(int i = 0; i < population->populationSz; i+=2){
        srand(microseg());

        int traits = newPopulation->traitsSz;
        int fIndex, sIndex, guard = 1;

        while(guard){
            fIndex = (rand() % traits) - 1;
            sIndex = (rand() % traits) - 1;

            bool oEquals = (sIndex >= fIndex);
            bool zero = ((fIndex <= 0) | (sIndex <= 0));
            bool total = ((fIndex == (traits - 1)) | (sIndex == (traits - 1)));
            if(!(oEquals | zero | total)){
                guard = 0;
            }
        }

        if(i == (population->populationSz - 1)){
            newPopulation[i] = crossover(population->population[i], population->population[0], 0, sIndex, fIndex);
            break;
        }else{
            newPopulation[i] = crossover(population->population[i], population->population[i+1], 0, sIndex, fIndex);
            newPopulation[i + 1] = crossover(population->population[i], population->population[i+1], 1, sIndex, fIndex);
        }

    }

    #ifdef printSteps
    printf("Mute individuals...\n");
    #endif

    for(int i = 0; i < population->populationSz; i++){
        mutation(&newPopulation[i], mutationP);
    }

    for(int c=0; c < population->populationSz; c++){
        
        for(int i=0; i<population->population[c].traitsSz; i++){
            population->population[c].traits[i] = newPopulation[c].traits[i];
        }

        free(newPopulation[c].traits);    
        
    }

    for(int c=0; c<population->bestIndividuo.traitsSz; c++){
        population->population[population->populationSz -1].traits[c] = population->bestIndividuo.traits[c];
    }
    population->population[population->populationSz -1].dist = population->bestIndividuo.dist;

}