#include <bits/stdc++.h>
using namespace std;

struct zol {
	int orwys; // oryginalna wysokosc
	int wys; //wysokosc po przeskalowaniu
	int nr; //ktory z kolei wchodzi do szeregu
};

bool compareOrwys (zol x, zol y) { //sortuje po wysokosci rosnaco
	return x.orwys < y.orwys;
}

bool compareNr (zol x, zol y) { //sortuje po nr czyli kolejnosci wchodzenia do szeregu rosnaco
	return x.nr < y.nr;
}

const int M = 1024*1024;
int D[2*M];
zol T[1000*1000+5];

int sum (int p, int k) {
	if (k == -1)
		return 0;
	p = M + p;
	k = M + k;
	int wynik = D[p];
	if (p != k)
		wynik += D[k];
	while (p/2 != k/2) {
		if (p%2 == 0) // jesli poczatek jest lewym synem
			wynik += D[p+1]; // dodajemy do wyniku wartosc z jego prawego brata
		if (k%2 == 1) // jesli koniec jest prawym synem
			wynik += D[k-1]; // dodajemy do wyniku wartosc z jego lewego brata
		p /= 2;
		k /= 2;
	}
	return wynik;
}

void dodaj (int poz, int x) {
	poz = M + poz;
	D[poz] += x;
	while (poz > 1) {
		poz /= 2;
		D[poz] = D[2*poz] + D[2*poz +1];
	}
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>> n;
	for (int i=0; i<n; i++) {
		cin>> T[i].orwys;
		T[i].nr = i;	
	}
	sort (T, T+n, compareOrwys);
	//skalowanie
	int x=0, ost = T[0].orwys;
	T[0].wys = 0;
	for (int i=0; i<n; i++) {
		if (T[i+1].orwys != ost) {
			ost = T[i+1].orwys;
			x++;
		}
		T[i+1].wys = x;
	}
	sort (T, T+n, compareNr);
	for (int i=0; i<n; i++) {		
		cout<< sum (0, T[i].wys - 1) << "\n";
		dodaj(T[i].wys, 1);
	}
	return 0;
}
