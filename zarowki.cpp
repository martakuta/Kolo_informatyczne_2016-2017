#include <bits/stdc++.h>
using namespace std;

int D[2*1024*1024];
const int M = 1024*1024; //wierzcholki drzewa numerowane od 0 do M-1, elementy ciagu od M+0 do M+n-1

int czytaj (int v) {
	v = M + v-1;
	int wynik = D[v];
	while (v>1) {
		v /= 2;
		wynik += D[v];
	}
	return wynik;
}

void dodaj (int l, int r, int x) {
	l = M + l-1;
	r = M + r-1;
	D[l] += x;
	if (l != r)
		D[r] += x;
	while (l/2 != r/2) {
		if (l%2 == 0)
			D[l+1] += x;
		if (r%2 == 1)
			D[r-1] += x;
		l /= 2;
		r /= 2;
	}
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	char lampa, pyt;
	cin>> n >> m;
	for (int i=0+M; i<n+M; i++) {
		cin>> lampa;
		if (lampa == 'x')
			D[i] = 0;
		else 
			D[i] = 1;
	}
	for (int i=0; i<m; i++) {
		cin>> pyt;
		if (pyt == 'Q') {
			int szukana;
			cin>> szukana;
			int stan = czytaj(szukana);
			if (stan%2 == 0)
				cout<< "OFF\n";
			else
				cout<< "ON\n";
		} else {
			int pocz, kon;
			cin>> pocz >> kon;
			dodaj (pocz, kon, 1);
		}
	}
	return 0;
}
