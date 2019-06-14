#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>
#include <random>
#include <string>
#include <sstream>
#include <ctime>

#include "metro.h"

using namespace std;	

int main(int argc, char** argv){
	
	double	T ;
	double	Tmin ;
	double Tmax ;
	double Tstep ;
	
	double	k ;
	double	mi ;
	double	J ;
	double	H ;

	int L ;
	int NMC ; // ilość iteracji 
	
	ofstream out;
	out.exceptions (ofstream::failbit | ifstream::badbit | ofstream::badbit);	
	
	ifstream in;
	in.exceptions (ofstream::failbit | ifstream::badbit | ofstream::badbit);	

	string param_name = "input.param";
	
	// read perameters
	
	try{
		in.open(param_name, std::ios::in);
	
		in >> param_name >> NMC;
		in >> param_name >> J;
		in >> param_name >> Tmin;
		in >> param_name >> Tmax;
		in >> param_name >> Tstep;
		in >> param_name >> k;
		in >> param_name >> H;
		in >> param_name >> L;
		in >> param_name >> mi;
		
		in.close();
	
	}catch(exception& e){
	      cout << e.what() << endl;
	}

	cout << "NMC = " << NMC << endl;
	cout << "J = " << J << endl;
	cout << "Tmin = " << Tmin << endl;
	cout << "Tmax = " << Tmax << endl;
	cout << "Tstep = " << Tstep << endl;
	cout << "k = " << k << endl;
	cout << "H = " << H << endl;
	cout << "L = " << L << endl;
	cout << "mi = " << mi << endl;



	

	int ** tablica = new int* [L];
	for(int i = 0; i < L; ++i){
		tablica[i] = new int [L];
	}


	try{
		string in_name = "input.dat";
		in.open( in_name , std::ios::in );
/*
// read input data
	  	for(int i = 0; i < L; ++i) {
			for(int j = 0; j < L; ++j){
				in >> tablica[i][j];
			}
   		}
*/
		in.close();
// wypełniamy losowo
		// declare random engine
		default_random_engine gen;

		gen.seed(time(0));
		
		
		double R;
		uniform_real_distribution<double> losR(0., 1.);
		for (int i = 0; i < L; ++i){
			for (int j = 0; j < L; ++j){
				R = losR(gen);
				if ( R > 0.4 ){ tablica[i][j] = 1; }
				else {tablica[i][j] = -1; }
			}
		}

// Checking input data
  	 	for(int i = 0; i < L; ++i) {
        		for(int j = 0; j < L; ++j){
				if(tablica[i][j] != 1 && tablica[i][j] != -1){
				cout << "Coś nie tak z danymi wejściowymi... wychodzenie." 
					<< endl;
				throw "Bad input!";
				}
			}
		    }

		double M=0;
		
		string out_name = "output.magnet";
		out.open( out_name , std::ios::out );

		T = Tmin;
		
		double MEAN = 0;
		int POWT = 10;


		while ( T < Tmax ){
			
			MEAN = 0;

			for( int xi = 0; xi < POWT; ++xi){
			for (int i = 0; i < NMC; ++i){
				montecarlo(tablica, L, J, H*mi, k*T, gen);
				//sekwencyjnie(tablica, L, J, H*mi, k*T, gen);
			}
			M = 0;
			for(int x = 0; x < L; ++x){
				for(int y = 0; y < L; ++y){
					M += tablica[x][y];
				}
			}
			M /= L*L;
	//		out << T << '\t' << M << endl;
	//		T += Tstep;

			MEAN += M;
			
			}
			out << T << '\t' << MEAN/POWT << endl;
			T += Tstep;
		}
		out.close();

		out_name = "output.dat";
		out.open( out_name , std::ios::out );
		// save output data
	  	for(int i = 0; i < L; ++i) {
			for(int j = 0; j < L; ++j){
				out << tablica[i][j] << '\t';
			}
			out << endl;
   		}
		out.close();

	}catch(exception& e){
	      cout << e.what() << endl;
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////

