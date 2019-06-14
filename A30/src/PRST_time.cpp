#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>
#include <random>

using namespace std;	

inline double fun( double X, double Y){ return Y*cos(X+Y*Y);}

int main(int argc, char** argv){
	
	int N = 100000;
	
	double I_H;
	
	double H;

	double I_ANAL= (-cos(10.)+cos(9.)+cos(2.)-cos(1.))	* 0.5;


	I_H=0.;

	H = sqrt( 2./N );	

	for(double iks = 0.; iks < 1.; iks+=H){
		for( double igrek = 1.; igrek < 3.; igrek += H){
			I_H += fun(iks,igrek);
		}
	}
	
	I_H *= H*H;			
	
	cout	<< I_H << " "
		<< I_ANAL << " "
		<< abs(I_ANAL-I_H) << endl; 

	return 0;
}


