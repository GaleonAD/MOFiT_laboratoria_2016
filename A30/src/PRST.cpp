#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>
#include <random>

using namespace std;	

inline double fun( double X, double Y){ return Y*cos(X+Y*Y);}

int main(int argc, char** argv){
	

	int M_MAX = 1000;

	double I_H;
	
	double H;

	double I_ANAL= (-cos(10.)+cos(9.)+cos(2.)-cos(1.))	* 0.5;


	ofstream out;
	out.exceptions ( ofstream::failbit | ifstream::badbit );	
	
	
	string out_name = "PRST.dat";

	try{
		out.open( out_name , std::ios::out );

		for(int M = 10; M < M_MAX ; ++M){
			
			I_H=0.;
			
			H = 1./M;

			for(int i = 0.; i <= M; ++i){
				for( int j = 0.; j <= 2*M; ++j){
					I_H += fun(i*H,1.+H*j);
				}
			}
	
			I_H *= H*H;			
	
			out 	<< 2*M*M << " " 
				<< I_H << " "
				<< I_ANAL << " "
				<< abs(I_ANAL-I_H) << endl; 
		 }
		out.close();

	}catch(exception& e){
	      cout << e.what() << endl;
	}

	return 0;
}


