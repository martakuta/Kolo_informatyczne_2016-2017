#include <iostream>
using namespace std;
int T[2000*1000+5];
int main () {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	long long  polowa=0;
	cin>> n;
	for (int i=0; i<n; i++) {
		cin>> T[i];
		T[n+i]= T[i];
		polowa += T[i];
	}
	T[2*n] = 0;
	polowa /= 2;
	int p=0, k=0;
	long long  przedzial=T[0];
	while (przedzial < polowa) {
		k++;
		przedzial += T[k];
	}
	long long maxprzedzial = przedzial - T[k];
	while (k<2*n) {
		while (przedzial>polowa) {
			przedzial -= T[p];
			p++;
		}
		if (przedzial > maxprzedzial)
			maxprzedzial = przedzial;
		while (przedzial <= polowa && k<2*n) {
			k++;
			przedzial += T[k];
			if (przedzial>maxprzedzial && przedzial<=polowa) 
				maxprzedzial = przedzial;
		}
		
	}
	cout<< maxprzedzial;
	return 0;
}
