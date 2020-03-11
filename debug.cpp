#include <iostream>
#include <cstdlib>
using namespace std;

int main () { 	
	int test;
	cin>> test;
	if (test == 0) {
		srand(430);
		int mod = 16;
		int n = rand()%mod;
		cout<< n << "\n";
		for (int i=2; i<=n; i++) 
			cout<< i << " " << rand()%(i-1)+1 << "\n";

	} else if (test == 1) {
		srand(105);
		int mod = 81;
		int n = rand()%mod+20;
		cout<< n << "\n";
		for (int i=2; i<=n; i++) 
			cout<< i << " " << rand()%(i-1)+1 << "\n";

	} else if (test == 2) {
		srand(30);
		int mod = 101;
		int n = rand()%mod+150;
		cout<< n << "\n";
		for (int i=2; i<=n; i++) 
			cout<< i << " " << rand()%(i-1)+1 << "\n";

	} else if (test == 3) {
		srand(22);
		int mod = 1001;
		int n = rand()%mod+1000;
		cout<< n << "\n";
		for (int i=2; i<=n; i++) 
			cout<< i << " " << rand()%(i-1)+1 << "\n";

	} else {
		srand(24);
		int mod = 500001;
		int n = rand()%mod+500000;
		cout<< n << "\n";
		for (int i=2; i<=n; i++) 
			cout<< i << " " << rand()%(i-1)+1 << "\n";
	}
	// 1-15 ziarno 430
	// 20-100 ziarno 105
	//150-250 ziarno 30
	//1000-2000 ziarno 22
	//500000-1000000 ziarno 24
	return 0;
}
