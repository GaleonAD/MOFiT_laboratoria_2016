#include <iostream>
#include <fstream>
#include <cmath>
#include <random>
#include <vector>

using namespace std;	

//inline double skalar(vector<double> V, vector<double> W){ return V[0]*W[0]+V[1]*W[1]+V[2]*W[2];}
inline double fun(double MASA, double X){ return MASA*X; }
inline double rho(vector<double> X){ return 1.; }


int main(int argc, char** argv){
	
	
	double bok = 1.;

	int N = atoi( argv[1] );
	
	vector<double> I_N;
	vector<double> x;
	default_random_engine gen;
	uniform_real_distribution<double> losX(-bok/2.,bok/2.);
	uniform_real_distribution<double> losY(-bok/2.,bok/2.);
	uniform_real_distribution<double> losZ(-bok/2.,bok/2.);
	
	I_N.push_back(0.);
	I_N.push_back(0.);
	I_N.push_back(0.);
	
	x.push_back(0.);
	x.push_back(0.);
	x.push_back(0.);

	for(int i = 0; i < N; ++i){
		x[0] = losX(gen);	
		x[1] = losX(gen);	
		x[2] = losX(gen);	
		I_N[0] += fun(rho(x),x[0]);
		I_N[1] += fun(rho(x),x[1]);
		I_N[2] += fun(rho(x),x[2]);
	}

	I_N[0] *= bok*bok*bok;
	I_N[1] *= bok*bok*bok;
	I_N[2] *= bok*bok*bok;
	
	I_N[0] /= N;
	I_N[1] /= N;
	I_N[2] /= N;


	cout	<< N << " " 
		<< I_N[0] << " " << I_N[1] << " " << I_N[2] << endl;

	return 0;
}


