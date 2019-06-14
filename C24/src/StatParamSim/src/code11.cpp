#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>
#include <random>
#include <vector>
#include <string>
#include <sstream>

using namespace std;	

void change (int & value);
double deltaE (vector<int> nb, int sk, double J, double Hmi);
bool check (vector<vector<int>> tablica, int x, int y, 
				double J, double Hmi, double kT);
vector<vector<int>> montecarlo (vector<vector<int>> tablica, 
				double J, double Hmi, double kT);
//vector<vector<int>> sekwencyjnie (vector<vector<int>> tablica, 
void sekwencyjnie (vector<vector<int>> & tablica, 
				double J, double Hmi, double kT);
bool check (vector<vector<int>> tablica, int x, int y, 
				double J, double Hmi, double kT);



int main(int argc, char** argv){
	
	
	double	T = 300.;
	double	k = 1.38e-23;
	double	mi = 1./2;
	double	J =  -1e-21;
	double	H = 0;
	
	int L = 32;
	int M = 1000; // ilość iteracji monte carlo


	ofstream out;
	out.exceptions ( ofstream::failbit | ifstream::badbit | ofstream::badbit );	
	
	ifstream in;
	in.exceptions ( ofstream::failbit | ifstream::badbit | ofstream::badbit );	
	
	string in_name = "input.dat";
	string out_name = "output.dat";

	vector<vector<int>> tablica (L, vector<int> (L, 1));


	try{
		in.open( in_name , std::ios::in );
		out.open( out_name , std::ios::out );

// read input data
	  	for(unsigned int i = 0; i < tablica.size(); ++i) {
			for(unsigned int j = 0; j < tablica[i].size(); ++j){
				in >> tablica[i][j];
			}
   		}

		in.close();
// Iterate and print values of vector
// checking
  	 	for(vector<int> n : tablica) {
        		for(int m : n){
				if(m != 1 && m != -1){
				cout << "Coś nie tak z danymi wejściowymi... wychodzenie." 
					<< endl;
				throw "Bad input!";
				}
//			cout << m << '\t';
			}
//		cout << '\n';
		    }

		

		for (int i = 0; i < M; ++i){
	//		tablica = montecarlo(tablica, J, H*mi, k*T);
			sekwencyjnie(tablica, J, H*mi, k*T);
		}
/*
		// save output data
	  	for(vector<int> n : tablica) {
			for(int m : n){
				out << m << '\t';
			}
			out << endl;
   		}
		out.close();
*/
	}catch(exception& e){
	      cout << e.what() << endl;
	}

	return 0;
}



void change (int & value){
	if (value == 1){value = -1;}
	else if (value == -1){value = 1;}
	else {	
		cout << "Coś jest nie tak!" << endl;
	}	
}

double deltaE (vector<int> nb, int sk, double J, double Hmi){
	double dE = 0.; 	// zaczynamy on policzenia sumy w nawiasie
	for(int i : nb){
		dE += (double) i;
	}
	dE *= J; 	// * całka wymiany
	dE += Hmi;	// + wpływ pola
	dE *= -2.*sk;	// * spin w sprawdzanym miejscu
	return dE;	
}

bool check (vector<vector<int>> tablica, int x, int y, 
				double J, double Hmi, double kT){
	bool condition;
	vector<int> nb; 
	int Lx = tablica.size();
	int Ly = tablica[0].size();
	
	// warunki brzegowe
	if (x == 0){
		nb.push_back(tablica[Lx-1][y]);
	}
	else {
		nb.push_back(tablica[x-1][y]);
	}
	////
	if (x == Lx-1){
		nb.push_back(tablica[0][y]);
	}
	else {
		nb.push_back(tablica[x+1][y]);
	}
	////
	if (y == 0){
		nb.push_back(tablica[x][Ly-1]);
	}
	else {
		nb.push_back(tablica[x][y-1]);
	}
	////
	if (y == Ly-1){
		nb.push_back(tablica[x][0]);
	}
	else {
		nb.push_back(tablica[x][y+1]);
	}
	////
	//cout << nb.size() << endl;
	// schemat Metropolisa
	double dE = deltaE(nb, tablica[x][y], J, Hmi);
	double R;
	default_random_engine gen;
	uniform_real_distribution<double> losR(0., 1.);
	if (dE < 0){
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

vector<vector<int>> montecarlo (vector<vector<int>> tablica, 
				double J, double Hmi, double kT){
	int N =  tablica.size() * tablica[0].size();

	default_random_engine gen;

	uniform_int_distribution<int> losX(0, tablica.size() - 1);
	uniform_int_distribution<int> losY(0, tablica[0].size() - 1);

	bool condition;

	for(int i = 0; i < N; ++i){
		int x = losX(gen);
		int y = losY(gen);
		condition = check (tablica, x, y, J, Hmi, kT);
		if ( condition ){
			change(tablica[x][y]);
		}
	}

	return tablica;
}
/*
vector<vector<int>> sekwencyjnie (vector<vector<int>> & tablica, 
				double J, double Hmi, double kT){


	for(unsigned int x = 0; x < tablica.size(); ++x) {
		for(unsigned int y = 0; y < tablica[x].size(); ++y){
			if( check (tablica, x, y, J, Hmi, kT) ){
				tablica[x][y] = change(tablica[x][y]);
			}
		}
   	}

	return tablica;
}*/

void sekwencyjnie (vector<vector<int>> & tablica, 
				double J, double Hmi, double kT){
	
	for(unsigned int x = 0; x < 32; ++x) {
		for(unsigned int y = 0; y < 32; ++y){
			if( check (tablica, x, y, J, Hmi, kT) ){
				change(tablica[x][y]);
			}
		}
   	}
/*
	for(unsigned int x = 0; x < tablica.size(); ++x) {
		for(unsigned int y = 0; y < tablica[x].size(); ++y){
			if( check (tablica, x, y, J, Hmi, kT) ){
				change(tablica[x][y]);
			}
		}
   	}
*/
}
