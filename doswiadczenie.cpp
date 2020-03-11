#include <bits/stdc++.h>
using namespace std;

multiset <int> s;
multiset <int>::iterator it1;
multiset <int>::iterator it2;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, zadanie, wynik, ilwiar=0, ilwszy=0;
	long long suma=0;
	cin>> n;

	while (ilwszy < 9) {
		cin>> zadanie;
		if (zadanie == 1) {
			cin>> wynik;
			ilwiar ++;
			ilwszy ++;
			suma += wynik;
			s.insert(wynik);
			
		} else 
			cout<< suma << "/" << ilwiar << "\n";
		n--;
	}

	while (ilwszy < 10) {
		cin>> zadanie;
		if (zadanie == 1) {
			cin>> wynik;
			ilwiar = 8;
			ilwszy ++;
			s.insert(wynik);
			it1 = s.begin();
			it2 = s.end();
			it2 --;
			suma = suma + wynik - *it1 - *it2;
		} else
			cout<< suma << "/" << ilwiar << "\n";
		n--;
	}

	for (int i=0; i<n; i++) {
		cin>> zadanie;
		if (zadanie == 1) {
			ilwszy ++;
			ilwiar ++;
			cin>> wynik;
			s.insert(wynik);
			if (wynik < *it1) {
				suma += *it1;
				it1 --;
			} else if (wynik >= *it1 && wynik < *it2) {
				suma += wynik;
			} else if (wynik >= *it2) {
				suma += *it2;
				it2 ++;
			}
			if (ilwszy % 10 == 0) {
				it1 ++;
				it2 --;
				suma = suma - *it1 - *it2;
				ilwiar -= 2;
			}
		} else 
			cout<< suma << "/" << ilwiar << "\n";
	}
	return 0;
}
