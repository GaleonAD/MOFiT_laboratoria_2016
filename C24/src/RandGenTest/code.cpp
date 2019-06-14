#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>
#include <random>
#include <string>
#include <ctime>

using namespace std;	


int main(int argc, char** argv){
	

	try{
		default_random_engine gen;
		default_random_engine gen2;
		
		gen2.seed (time(0));

		uniform_real_distribution<double> losR(0., 1.);
		double R, R2;
		int L = 10;

		for (int i = 0; i < L; ++i){
			R = losR(gen);
			R2 = losR(gen2);
			cout << R << "\t" << R2 << endl;
		}


	}catch(exception& e){
	      cout << e.what() << endl;
	}

	return 0;
}


