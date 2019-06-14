#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>
#include <random>
#include <string>
#include <sstream>

using namespace std;	

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



int main(int argc, char** argv){
	
	double	T ;
	double	k ;
	double	mi ;
	double	J ;
	double	H ;
	
	int L ;
	int NMC ; // ilość iteracji monte carlo
	
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
		in >> param_name >> T;
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
	cout << "T = " << T << endl;
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
		for (int i = 0; i < NMC; ++i){
//			montecarlo(tablica, L, J, H*mi, k*T, gen);
			sekwencyjnie(tablica, L, J, H*mi, k*T, gen);
			for(int x = 0; x < L; ++x){
				for(int y = 0; y < L; ++y){
					M += tablica[x][y];
				}
			}
			M /= L*L;
			out << i << '\t' << M << endl;
			//cout << "M(" << i << ") = " << M << endl;
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


double deltaE (int * nb, int sk, double J, double Hmi){
	double dE = 0.; 	// zaczynamy on policzenia sumy w nawiasie
	for(int i = 0; i < 4; ++i){
		dE += (double) nb[i];
	}
	dE *= J; 	// * całka wymiany
	dE += Hmi;	// + wpływ pola
	dE *= -2.*sk;	// * spin w sprawdzanym miejscu
	return dE;	
}

bool check (int ** tablica, int L, int x, int y, 
				double J, double Hmi, double kT, 
				default_random_engine &gen){
	bool condition;
	int nb[4];
	
	// warunki brzegowe
	if (x == 0){
		nb[0] = tablica[L-1][y];
	}
	else {
		nb[0] = tablica[x-1][y];
	}
	////
	if (x == L-1){
		nb[1] = tablica[0][y];
	}
	else {
		nb[1] = tablica[x+1][y];
	}
	////
	if (y == 0){
		nb[2] = tablica[x][L-1];
	}
	else {
		nb[2] = tablica[x][y-1];
	}
	////
	if (y == L-1){
		nb[3] = tablica[x][0];
	}
	else {
		nb[3] = tablica[x][y+1];
	}
	////
	// schemat Metropolisa
	double dE = deltaE(nb, tablica[x][y], J, Hmi);
	double R;
	uniform_real_distribution<double> losR(0., 1.);
	if (dE <= 0){
		condition = true;
	}
	else {
		R = losR(gen);
		if (R < exp(-dE/kT)){
			condition = true;
		}
		else {
			condition = false;
		}
	}

	return condition;
}

void montecarlo (int ** & tablica, int L, double J, 
			double Hmi, double kT, default_random_engine &gen ){
	
	int N =  L * L;

//	default_random_engine gen;

	uniform_int_distribution<int> los(0, L - 1);

	bool condition;

	for(int i = 0; i < N; ++i){
		int x = los(gen);
		int y = los(gen);
		condition = check (tablica, L, x, y, J, Hmi, kT, gen);
		if ( condition ){
			tablica[x][y] *= -1;
		}
	}
}


void sekwencyjnie (int ** & tablica, int L,
				double J, double Hmi, double kT, default_random_engine &gen){
	bool condition;
	for(int x = 0; x < L; ++x) {
		for(int y = 0; y < L; ++y){
			condition = check (tablica, L, x, y, J, Hmi, kT, gen);
			if( condition ){
				tablica[x][y] *= -1;
			}
		}
   	}
}
