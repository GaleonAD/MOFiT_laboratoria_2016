#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>
#include <random>

using namespace std;	

inline double fun( double X, double Y){ return Y*cos(X+Y*Y);}

int main(int argc, char** argv){
	
	
	double N_MAX = 2000000;

	double I_N;

	double I_ANAL= (-cos(10.)+cos(9.)+cos(2.)-cos(1.))	* 0.5;

	default_random_engine gen;
	uniform_real_distribution<double> losX(0.0,1.0);
	uniform_real_distribution<double> losY(1.0,3.0);

	ofstream out;
	out.exceptions ( ofstream::failbit | ifstream::badbit );	
	
	
	string out_name = "MC.dat";

	try{
		out.open( out_name , std::ios::out );

		for(int N = 100; N < N_MAX ; N *=1.2 ){
			
			N = int(N) ;

			I_N=0.; 

			for(int i = 0; i < N; ++i){
				I_N += fun(losX(gen),losY(gen));
			}
	
			I_N *= 2.;
			I_N /= N;
	
			out 	<< N << " " 
				<< I_N << " "
				<< I_ANAL << " "
				<< abs(I_ANAL-I_N) << endl; 
		 }
		out.close();

	}catch(exception& e){
	      cout << e.what() << endl;
	}

	return 0;
}


