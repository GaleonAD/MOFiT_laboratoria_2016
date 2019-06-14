#include <iostream>
#include <fstream>
#include <cmath>
#include <random>
#include <vector>

using namespace std;	

inline double rho(vector<double> X){ return 1.; }
inline double skalar(vector<double> V, vector<double> W){ return V[0]*W[0]+V[1]*W[1]+V[2]*W[2];}
double fun(double MASA,vector<double> X, vector<double> P){ 
		vector<double> D;

		double xp = skalar(X , P);

		D.push_back(X[0] - xp*P[0]);
		D.push_back(X[1] - xp*P[1]);
		D.push_back(X[2] - xp*P[2]);

		return MASA*skalar(D,D);
		}


int main(int argc, char** argv){
	
	
	double bok = 1.;

	int N = atoi( argv[1] );
	
	double I_N=0.;
	vector<double> x,prosta;
	default_random_engine gen;
	uniform_real_distribution<double> losX(-bok/2.,bok/2.);
	uniform_real_distribution<double> losY(-bok/2.,bok/2.);
	uniform_real_distribution<double> losZ(-bok/2.,bok/2.);
	
	prosta.push_back(0.);
	prosta.push_back(0.);
	prosta.push_back(1.);

	double p_norm = sqrt(skalar(prosta,prosta));
	prosta[1] /= p_norm;
	prosta[2] /= p_norm;
	prosta[0] /= p_norm;

	x.push_back(0.);
	x.push_back(0.);
	x.push_back(0.);
	
	for(int i = 0; i < N; ++i){
		x[0] = losX(gen);
		x[1] = losY(gen);
		x[2] = losZ(gen);
		I_N += fun(rho(x),x,prosta);
	}

	I_N *= bok*bok*bok;
	I_N /= N;

	cout	<< N << " " 
		<< I_N << endl;

	return 0;
}


