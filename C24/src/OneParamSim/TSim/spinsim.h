#ifndef SPINSIM_H
#define SPINSIM_H

#include <iostream>
#include <cmath>
#include <exception>
#include <random>
#include <ctime>

double deltaE (int * nb, int sk, double J, double Hmi);

void montecarlo (int ** & tablica, int L,
				double J, double Hmi, double kT, 
				default_random_engine & gen);

void sekwencyjnie (int ** & tablica, int L, 
				double J, double Hmi, double kT, 
				default_random_engine & gen);

bool check (int ** tablica, int L, int x, int y, 
				double J, double Hmi, double kT, 
				default_random_engine & gen);

#endif
