#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>
#include <random>
#include <vector>

using namespace std;	

inline double norm( double X, double Y, double Z){ return X*X+Y*Y+Z*Z;}
double fun( 

int main(int argc, char** argv){
	
	
	double N_MAX = 1000;
	double I_N;
	double I_ANAL= 1./6.;

	default_random_engine gen;

	double bok = 1.;

	uniform_real_distribution<double> losX(-bok/2.,bok/2.);
	uniform_real_distribution<double> losY(-bok/2.,bok/2.);
	uniform_real_distribution<double> losZ(-bok/2.,bok/2.);

	ofstream out;
	out.exceptions ( ofstream::failbit | ifstream::badbit );	
	
	
	string out_name = "data.dat";

	try{
		out.open( out_name , std::ios::out );

		//for(int N = 100; N < N_MAX ; N *=1.2 ){
			
			//N = int(N) ;
			int N = 100000;
			//


			I_N=0.; 

			for(int i = 0; i < N; ++i){
				I_N += fun(losX(gen),losY(gen),losZ(gen));
			}
	
			I_N *= bok*bok*bok;
			I_N /= N;
	
			cout	<< N << " " 
				<< I_N << " "
				<< I_ANAL << " "
				<< abs(I_ANAL-I_N) << endl; 
		 //}
		out.close();

	}catch(exception& e){
	      cout << e.what() << endl;
	}

	return 0;
}


