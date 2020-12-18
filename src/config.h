#ifndef CONFIG_H
#define CONFIG_H

#define ENABLE_GNUPLOT 1
#define GNUPLOT "gnuplot -persist"
#define PLOT 1
#define ROUTE_FILE "../output/test1.txt"

/* Global definitions */
const int MAX_GEN = 100;
const int POPULATION_SIZE = 10000;
const int ELITE_SIZE = 0.1*POPULATION_SIZE;
const double PERFECT_SCORE = 1;
const int ENABLE_OUTPUT = 1;
const int GENERATE_ROUTE = 1;
const double P_MAX = 0.05;
const double P_MIN = 0.01;

#endif