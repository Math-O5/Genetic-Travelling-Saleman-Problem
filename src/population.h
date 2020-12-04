#ifndef POPULATION_H
#define POPULATION_H

#include<string>
#include<vector>
#include "DNA.h"

using namespace std;

const double PERFECT_SCORE = 1;

/*
    Population is a collection of elements
    Element or DNA is a collection of genes

    Target -> optimal solution for the element

*/
class Population {
    public:
        vector<vector<double>> target;             
        double mutation_rate;
        int popmax, generation, elite;
        bool is_finish;
        DNA best_individual;        // best individual at moment
        vector<DNA> individuals;    // actual generation
        vector<DNA> mating_pool;

        Population(const vector<vector<double>>& target, double mutation, int popmax, int elite) {
                this->target = target;
                this->mutation_rate = mutation;
                this->popmax = popmax;
                this->elite = elite;
                generation = 0;
                is_finish = false;
                for(int i = 0; i < popmax; ++i) {
                    individuals.push_back(DNA((int)target.size()));
                }
        }

        /* initialize random seed: */
        void start_clock() {
            srand (time(NULL));
        }
        // Select individuals with more fitness most likely to survive
        // Select the BESTEST individuals based on fitness
        void selection() {

            double max_fitness = 0.0;
            for(int i = 0; i < popmax; ++i) {
                max_fitness = max(max_fitness, this->individuals[i].fitness);
            }
            max_fitness *= 100;
            for(int i = 0; i < popmax; ++i) {
                int n = 1;
                if(max_fitness > 0)
                    n = ((double)(100*this->individuals[i].fitness) / (double) max_fitness);
                for(int j = 0; j < n; ++j)
                    mating_pool.push_back(DNA(this->individuals[i]));
            }
        }

        //
        void generate() {
            // cout << "Start generate\n";
            int num_individuals = (int)this->mating_pool.size();
            for(int i = 0; i < popmax; ++i) {
                // cout << "Start crossover\n";
                int father = rand() % num_individuals;
                int mother = rand() % num_individuals;
                DNA child = DNA(this->mating_pool[father].crossover(this->mating_pool[mother]));
                // cout << "CHILD FIT: " << child.fitness << endl; 
                child.mutate(this->mutation_rate);
                this->individuals[i] = child;
                // cout << "chil " << child.genes << endl;
            }
            // cout << "End generate\n";
            // Next generation is made
            this->generation++;
            mating_pool.clear();
        }

        // Calculate fitness for every individual
        void calc_fitness() {  
            // cout << "Eszn\n";
            for(int i = 0; i < popmax; ++i) {
                individuals[i].calc_fitness(target);
            } 
        }

        void evaluete() {
            double max_fit = -1.0;
            int j = 0;
            for(int i = 0; i < popmax; ++i) {
                // cout << individuals[i].fitness << endl;
                if(individuals[i].fitness > max_fit) {
                    max_fit = individuals[i].fitness;
                    j = i;
                }
            }
            this->best_individual = DNA(individuals[j]);
            cout << "Best fitness: " << best_individual.genes << ' ' << best_individual.fitness << '\n';
        }

        bool get_is_finish() {
            if(best_individual.fitness >= PERFECT_SCORE)
                return this->is_finish = true;
            return false;
        }
};

#endif