#include<random>
#include<iostream>
#include<time.h>

using namespace std;


int main () {
	default_random_engine gen;
	uniform_real_distribution<double> losR(0., 1.);

	int N = 10;
	for (int i = 0; i < N; ++i){
		cout << "L_fun = " << fun() << endl;
		cout << "L_main = " << losR(gen) << endl;
	}
	return 0;
}
