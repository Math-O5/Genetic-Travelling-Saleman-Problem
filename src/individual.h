#ifndef Individual_H
#define Individual_H

#include <set>
#include <time.h>       /* time */
#include <string>
#include <vector>
#include <math.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <algorithm>    // std::random_shuffle


using namespace std;

const double P_MAX = 0.05;
const double P_MIN = 0.01;

/*
    Individual is a collection genes.
    Genes is expreseed as tours
*/
class Individual { 
    public:
        // A individual is a sequence of genes(cities)
        std::vector<int> genes; 

        // The rank of the individual and the distance of this tour
        double fitness, distance;

        // Length of genes(tour)
        int length;

        Individual() {
            fitness = -1;
            length = 0;
            distance = 0; 
        };

        Individual(const Individual& Individual) {
            this->genes = Individual.genes;
            this->fitness = Individual.fitness;
            this->length = Individual.length;
            this->distance = Individual.distance;
        };

        Individual(int length) {
            this->fitness = 0;
            this->distance = -1; // no defined
            this->genes = new_tour(length);
            this->length = length;
        }

        /*
            Random generator number from (1 to i-1)
        */
        int static random_number(int i) { 
            return rand()%i;
        }

        /*
            Generate new tour(individual) ramdomly
        */
        vector<int> new_tour(int n) {
            vector<int> tour;

            // Tour first is a sequence from 1 to n
            for (int i = 1; i <= n; ++i)
                tour.push_back(i); 

            // Suffle initial tour
            random_shuffle ( tour.begin(), tour.end(), random_number);

            return tour;   
        }

        /*
            This function calculate the score of this individual
        */
        void calc_fitness(const vector<vector<double>>& matrix_distance) {
            // Distance of the tour
            double sum = 0.0;

            // Acumulate the distance of the tour in sum
            for(int i = 0; i < this->length; ++i) {
                sum += matrix_distance[this->genes[i]-1][this->genes[(i + 1 ) % this->length]-1];
            }
            
            // Update distance and fitness 
            this->distance = sum;
            this->fitness = 1 / (double)sum;
        }

        /*
            Crossover operation mescle two individuals to generate a child
        */
        Individual crossover(Individual partner) {
            Individual child = Individual();
            
            // This colletction ensure that the city appear only one time in the tour
            set<int> new_route;

            // Two ramdomly position with n1 < n2
            int n1 = rand() % this->length,
                n2 = rand() % (this->length - n1) + n1; 

            // Copy a slice of [n1, n2) to child
            for(int i = n1; i < n2; ++i) {
                child.genes.push_back(this->genes[i]);
                new_route.insert(this->genes[i]);
            }

            // The gap is the size of how many gene is missing in child
            int gap = this->length - (child.length);

            // Fill gap with genes partner 
            for(int i = 0; i < (int)partner.length; ++i) {
                if(new_route.find(partner.genes[i]) == new_route.end()) {
                    new_route.insert(partner.genes[i]);
                    child.genes.push_back(partner.genes[i]);
                }
            }
            child.length = this->length;
            
            // Clean set
            new_route.clear();

            return child;
        }

        /*
            Mutation is a operation the ramdomly swap two genes of the individual
            Chance of a gene suffer a mutation is adaptive mutation probability
        */
        void mutate(const double& fitness_avg, const double& fitness_max) {
            for(int i = 0; i < genes.size(); ++i) {
                double p = P_MAX * (P_MAX - P_MIN) * (fitness - fitness_avg) / (fitness_max - fitness_avg);
                if (rand()/(double)RAND_MAX >=  p) {
                     int n1 = rand() % length,
                         n2 = rand() % length; 
                    swap(genes[n1], genes[n2]);
                }
            }

    }

    /*
        Destructor
    */
    ~Individual() {
        this->genes.clear();
    }
};


#endif