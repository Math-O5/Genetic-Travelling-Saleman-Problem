#ifndef DNA_H
#define DNA_H

#include<string>
#include<vector>
#include<stdlib.h>     /* srand, rand */
#include<time.h>       /* time */
#include<iostream>
#include<math.h>
#include<algorithm>    // std::random_shuffle
#include<set>

using namespace std;

const double P_MAX = 0.05;
const double P_MIN = 0.01;

/*
    DNA is a collection genes.
    Genes is expreseed as tours
*/
class DNA { 
    public:
        vector<int> genes; // tour
        double fitness, distance;
        int length;

        DNA() {
            fitness = -1;
            length = 0;
            distance = 0; 
        };

        DNA(const DNA& dna) {
            this->genes = dna.genes;
            this->fitness = dna.fitness;
            this->length = dna.length;
            this->distance = dna.distance;
        };

        DNA(int length) {
            this->fitness = 0;
            this->distance = -1; // no defined
            this->genes = new_tour(length);
            this->length = length;
        }

        // random generator function:
        int static random_number(int i) { 
            return rand()%i;
        }

        vector<int> new_tour(int n) {
            vector<int> tour;

            // set default tour sequencial
            for (int i = 1; i <= n; ++i)
                tour.push_back(i); // 1 2 ... n

            // using built-in random generator:
            random_shuffle(tour.begin(), tour.end());

            // using myrandom:
            random_shuffle ( tour.begin(), tour.end(), random_number);

            return tour;   
        }

        /*
            This function calculate the score of this indi
        */
        void calc_fitness(const vector<vector<double>> matrix_distance) {
            double fit = 0.0;
            double sum = 0.0;

            for(int i = 0; i < this->length; ++i) {
                sum += matrix_distance[this->genes[i]-1][this->genes[(i + 1 ) % this->length]-1];
            }
            
            // update distance 
            this->distance = sum;
            this->fitness = 1 / (double)sum;
        }

        /*
            Mescle father and mother, generate a CHILD
        */
        DNA crossover(DNA partner) {
            DNA child = DNA();
            set<int> new_route;

            int n1 = rand() % this->length,
                n2 = rand() % (this->length - n1) + n1; 

            // Copy a slice of (n1, n2) to child
            for(int i = n1; i < n2; ++i) {
                child.genes.push_back(this->genes[i]);
                new_route.insert(this->genes[i]);
            }

            // The gap is how many gene is missing in child
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
            Chance of a gene suffer a mutation
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
        Destructot
    */
    ~DNA() {
        this->genes.clear();
    }
};


#endif