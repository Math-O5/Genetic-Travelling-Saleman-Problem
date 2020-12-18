#ifndef POPULATION_H
#define POPULATION_H
#include "individual.h"
#include <string>
#include <vector>   
#include <algorithm> // swap

using namespace std;

const double PERFECT_SCORE = 1;

/*
    Population is a collection of individuals
*/
class Population {
    public:
        // Distances between cities
        vector<vector<double>> distance_matrix; 

        // Average fitness and MAX fitness of the actual population            
        double fitness_avg, fitness_max;

        // Max population, generation actual and the size of elite
        int popmax, generation, elite;  

        // Store the best individual from all populations
        Individual best_individual;

        // Actual population: collection of individuals
        vector<Individual> individuals;

        Population(const vector<vector<double>>& distance_matrix, int popmax, int elite) {
                this->start_clock();
                this->distance_matrix = distance_matrix;
                this->popmax = popmax;
                this->elite = elite;
                generation = 0;
                for(int i = 0; i < popmax; ++i) {
                    individuals.push_back(Individual((int)distance_matrix.size()));
                }
                // if (ENABLE_OUTPUT) {
                //     cout << this->popmax << endl;
                //     for (auto v : distance_matrix) {
                //         for (auto x : v) {
                //         cout << x << " ";
                //     }
                //     cout << endl;
                // }
                // }
        }

        /* 
            Initialize random seed
        */
        void start_clock() {
            srand (time(NULL));
        }

        void swap(int i, int j) {
            Individual aux = this->individuals[i];
            this->individuals[i] = this->individuals[j];
            this->individuals[j] = aux;
        }

        /*
            Compare individual by fitness function compare
        */
        bool static sort_individuals(const Individual& ind_a, const Individual& ind_b) {
            return (ind_a.fitness > ind_b.fitness);
        }

        /*
            Random generator function:
        */
        int random_number(int i) { 
            return rand()%i;
        }

        /*
            This function ramdom swicth on elite individual with an elite one.
        */
        void tournament_of_two() {
            for(int i = 0; i < 2; ++i) {
                int falling = (int)(rand() % this->elite);
                int rising =  (int)(rand() % (this->popmax-this->elite)) + this->elite - 1;
                // cout << "falling " << falling << " rsising" << rising << endl;
                swap(falling, rising);
            }
        }

        /* 
            Select calculate the fitness which tell which is the most likely to survive

            This also save the best invidividual until now
        */
        void selection() {

            double sum_fitness = 0.0;            

            // Sum all fitness 
            for(int i = 0; i < popmax; ++i) {
                sum_fitness += this->individuals[i].fitness;
            }

            // Sort individuals by decrement fitness 
            sort(individuals.begin(), individuals.end(), sort_individuals);
            
            // Save fitness average and max of this population
            this->fitness_avg = sum_fitness / popmax;
            this->fitness_max = individuals[0].fitness;

            // print_fitness();

            // Check if there is a new best individual
            if(individuals[0].fitness > this->best_individual.fitness)
                this->best_individual = Individual(individuals[0]);

            // Change one individual of elite for one individual with poor fitness
            if(this->elite > 2)
                tournament_of_two();
        }

        /*
            This evaluate crossover and the mutation fr each individual
        */
        void generate() {
            for(int i = elite; i < popmax; ++i) {
                int elite_index = (int)(rand() % elite);
                Individual child = Individual(this->individuals[i].crossover(this->individuals[elite_index]));
                child.mutate(this->fitness_avg, this->fitness_max);
                this->individuals[i] = child;
            }
            this->generation++;
        }

        // Calculate fitness for every individual
        void calc_fitness() {  

            // Acumulate the sum of all fitness
            double sum = 0.0;

            // Evaluate fitness as fit = 1 / d
            for(int i = 0; i < popmax; ++i) {
                individuals[i].calc_fitness(distance_matrix);
                sum += individuals[i].fitness;
            } 
            // Normalize with fit/total fit 
            for(int i = 0; i < popmax; ++i) {
                individuals[i].prob_fit /= sum;
            } 
        }

        /*
            Switch two ramdomly position in the tour for each individual

            This function aim improve local search
        */
        void evolutionary_reversal() {
            int rand_number_one; 
            int rand_number_two;

            for(int i = 0; i < this->popmax; ++i) {
                rand_number_one = random_number(this->individuals[i].length);
                rand_number_two = random_number(this->individuals[i].length);
                swap(this->individuals[i].genes[rand_number_one], 
                    this->individuals[i].genes[rand_number_two]);
            }
        }

        ~Population() {
            this->individuals.clear();
        }
};

#endif