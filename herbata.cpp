#include <bits/stdc++.h>
using namespace std;

const int M = 1025*256;
int D[M*2];

void dodaj (int poz, int x) {
	poz = M + poz-1;
	D[poz] = x;
	while (poz > 1) {
		poz /= 2;
		D[poz] = D[poz*2] + D[poz*2 +1];
	}
}

int sumuj (int p, int k) {
	p = M + p-1;
	k = M + k-1;
	int wynik = D[p];
	if (p != k)
		wynik += D[k];
	while (p/2 != k/2) {
		if (p%2 == 0)
			wynik += D[p+1];
		if (k%2 == 1)
			wynik += D[k-1];
		p /= 2;
		k /= 2;
	}
	return wynik;
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	bool dzialanie;
	cin>> n >> m;
	for (int i=M; i<M+n; i++)
		cin>> D[i];
	for (int i=0; i<m; i++) {
		cin>> dzialanie;
		if (dzialanie == 1) {
			int p, k;
			cin>> p >> k;
			int suma = sumuj(p, k);
			long long wynik = 0;
			for (int j=M+p-1; j<=M+k-1; j++) 
				wynik += D[j]*(suma-D[j]);
			wynik /= 2;
			cout<< wynik << "\n";			
		} else {
			int pudelko, ile;
			cin>> pudelko >> ile;
			dodaj(pudelko, ile);
		}
	}
	return 0;
}
