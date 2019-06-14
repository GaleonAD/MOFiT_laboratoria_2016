#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>
#include <random>
#include <vector>

using namespace std;	

short change(short value){
	if (value == 1){return -1;}
	else if (value == -1){return 1;}
	else {return 0;}
}

double deltaE(vector<short> nb, sk, J, Hmi){
	double dE = 0.; 	// zaczynamy on policzenia sumy w nawiasie
	for(short i : nb){
		dE += (double) i;
	}
	dE *= J;
	dE += Hmi;
	dE *= -2.*sk;
	return dE;	
}

vector<vector<short>> montecarlo (vector<vector<short>> tablica, 
									double J, double Hmi, double kT){
	int N =  tablica.size() * tablica[0].size();

	default_random_engine gen;

	uniform_int_distribution<int> losX(0, L-1);
	uniform_int_distribution<int> losY(0, L-1);
	

	return tablica;
}

vector<vector<short>> sekwencyjnie (vector<vector<short>> tablica, 
									double J, double Hmi, double kT){


	return tablica;
}

int main(int argc, char** argv){
	
	
	double	T = 300;
	double	k = 1.38e-23;
	double	mi = 1./2;
	double	J =  -1e-21;
	double	H = 0;
	
	int L = 32;
//	int N = L*L;
	int M = 1000; // ilość iteracji monte carlo


	ofstream out;
	out.exceptions ( ofstream::failbit | ifstream::badbit | ofstream::badbit );	
	
	ofstream in;
	in.exceptions ( ofstream::failbit | ifstream::badbit | ofstream::badbit );	
	
	string out_name = "output.dat";
	string in_name = "input.dat";

	vector<vector<short>> tablica (L, vector<short> (L, 1));

// Iterate and print values of vector
/*    for(vector<short> n : tablica) {
        for(short m : n){
			cout << m << '\t';
		}
		cout << '\n';
    }
*/

	try{
		in.open( in_name , std::ios::in );
		out.open( out_name , std::ios::out );


		montecarlo( tablica, J, H*mi, k*T);


		out.close();
		in.close();

	}catch(exception& e){
	      cout << e.what() << endl;
	}

	return 0;
}


