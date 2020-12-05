#ifndef POPULATION_H
#define POPULATION_H

#include<string>
#include<vector>   
#include <algorithm> // swap
#include "DNA.h"

using namespace std;

const double PERFECT_SCORE = 1;

bool sort_individuals(const DNA& ind_a, const DNA& ind_b) {
    return (ind_a.fitness > ind_b.fitness);
}

void suffle(vector<double>& tour, int num) {
    int length = (int)tour.size();
    for(int i = 0; i < num; ++i) {
        int n1 = rand() % length,
            n2 = rand() % length;
        swap(tour[n1], tour[n2]);
    }
}

/*
    Population is a collection of elements
    Element or DNA is a collection of genes

    distance_matrix -> optimal solution for the element

*/
class Population {
    public:
        vector<vector<double>> distance_matrix;             
        double fitness_avg, fitness_max;
        int popmax, generation, elite;
        bool is_finish;
        DNA best_individual;        // best individual at moment
        vector<DNA> individuals;    // actual generation
        vector<DNA> mating_pool;

        Population(const vector<vector<double>>& distance_matrix, int popmax, int elite) {
                this->start_clock();
                this->distance_matrix = distance_matrix;
                this->popmax = popmax;
                this->elite = elite;
                generation = 0;
                is_finish = false;
                for(int i = 0; i < popmax; ++i) {
                    individuals.push_back(DNA((int)distance_matrix.size()));
                }
        }

        /* initialize random seed: */
        void start_clock() {
            srand (time(NULL));
        }

        /* Print fitness */
        void print_fitness() {
            cout << "Fits: ";
            for(int i = 0; i < popmax; ++i)
                cout << individuals[i].fitness << ' ';
            cout << endl;
        }

        /*
            Battle of bank corruping and luck

            Forces of destination that can not be changed.  
        */
        void tournament_of_two() {
            for(int i = 0; i < 2; ++i) {
                int falling = (int)(rand() % this->elite);
                int rising =  (int)(rand() % (this->popmax-this->elite)) + this->elite-2;
                swap(this->individuals[falling], this->individuals[rising]);
            }
        }

        /* 
            Select individuals with more fitness most likely to survive
            Save the best invidividual
        */
        void selection() {

            double sum_fitness = 0.0;            

            // Sum all fitness 
            for(int i = 0; i < popmax; ++i) {
                for(int j = 0; j < this->individuals[i].length; ++j) {
                    cout << this->individuals[i].genes[j] << ' ';
                }
                cout << endl;              
                sum_fitness += this->individuals[i].fitness;
            }
            // Sort individuals by decrement fitness 
            sort(individuals.begin(), individuals.end(), sort_individuals);
            
            // Save fitness average and max of this population
            this->fitness_avg = sum_fitness / popmax;
            this->fitness_max = individuals[0].fitness;

            print_fitness();

            // Check if there is a new best individual
            if(individuals[0].fitness > this->best_individual.fitness)
                this->best_individual = DNA(individuals[0]);

            // Change two of elite for two individual with poor fitness
            tournament_of_two();
        }

        /*
        
        */
        void generate() {
            // cout << "Start generate\n";
            for(int i = 0; i < popmax; ++i) {
                // cout << "Start crossover\n";
                int elite_index = (int)(rand() % elite);
                // DNA child = DNA(this->individuals[i].crossover(this->individuals[elite_index]));
                // cout << "CHILD FIT: " << child.fitness << endl; 
                // child.mutate(this->fitness_avg, this->fitness_max);
                individuals[i].mutate(this->fitness_avg, this->fitness_max);
                // this->individuals[i] = child;
                // cout << "chil " << child.genes << endl;
            }
            // cout << "End generate\n";
            // Next generation is made
            this->generation++;
        }

        // Calculate fitness for every individual
        void calc_fitness() {  
            double sum = 0.0;

            // Evaluate fitness as fit = 1 / d
            for(int i = 0; i < popmax; ++i) {
                individuals[i].calc_fitness(distance_matrix);
                sum += individuals[i].fitness;
            } 

            // Normalize with fit/total fit 
            for(int i = 0; i < popmax; ++i) {
                individuals[i].fitness /= sum;
            } 
        }

        bool get_is_finish() {
            if(best_individual.fitness >= PERFECT_SCORE)
                return this->is_finish = true;
            return false;
        }
};

#endif