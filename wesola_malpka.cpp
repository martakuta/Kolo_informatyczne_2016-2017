#include <bits/stdc++.h>
using namespace std;

int NWD(int a, int b) {
	while (b>0) {
		int pom = a;
		a = b;
		b = pom%b;
	}
	return a;
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, klatki, skok;
	cin>> n;
	for (int i=0; i<n; i++) {
		cin>> klatki >> skok;
		if (skok > klatki)
			skok -= klatki;
		int wynik = klatki / NWD(klatki, skok) ;
		cout<< wynik << "\n";
	}
	return 0;
}
