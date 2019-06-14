#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>
#include <random>

using namespace std;	

inline double fun( double X, double Y){ return Y*cos(X+Y*Y);}

int main(int argc, char** argv){

	int N = 200000;	
	
	double I_N;

	double I_ANAL= (-cos(10.)+cos(9.)+cos(2.)-cos(1.))	* 0.5;

	default_random_engine gen;
	uniform_real_distribution<double> losX(0.0,1.0);
	uniform_real_distribution<double> losY(1.0,3.0);

	I_N=0.; 

	for(int i = 0; i < N; ++i){
		I_N += fun(losX(gen),losY(gen));
	}
	
	I_N *= 2.;
	I_N /= N;
	
	cout 	<< I_N << " "
		<< I_ANAL << " "
		<< abs(I_ANAL-I_N) << endl; 

	return 0;
}


