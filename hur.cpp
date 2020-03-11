#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair

multiset <pair <int, int> > s;
multiset <pair <int, int> >::iterator it;
int wolne[250*1000+5];
bool zrealizowane[250*1000+5];
int wolneoficjalne[250*1000+5];
int ilosc=0;

void bierz (int ile,  int x) {
//	cout<< "\nbierz" << ile << "," << x << "\n";
	if (wolne[x] >= ile) {
		wolne[x] -= ile;
		ilosc ++;
//		cout<< "ilosc++\n";
	} else {
		ile -= wolne[x];
		wolne[x] = 0;
		x--;
		if (x>0)
			bierz (ile,  x);
	}
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, b;
	cin>> n;
	for (int i=1; i<=n; i++) {
		cin>> wolne[i];
		wolneoficjalne[i] = wolne[i];
	}
	for (int i=1; i<=n; i++) {
		cin>> b;
		s.insert(mp(b, i));
	}
	while (!s.empty()) {
		pair <int, int> p = *s.begin();
//		x = xoficjalne;
		int bylo = ilosc;
		bierz(p.f, p.s);
		s.erase(p);
/*		for (int i=1; i<=n; i++)
			cout<< wolne[i] << " ";
		cout<< "\n";*/
		if (ilosc > bylo) {
			for (int i=p.s; i>0; i--) 
				wolneoficjalne[i] = wolne[i];
			zrealizowane[p.s] = 1;
		} else {
			for (int i=p.s; i>0; i--)
				wolne[i] = wolneoficjalne[i];
			ilosc = bylo;
		}
/*		for (int i=1; i<=n; i++)
			cout<< wolneoficjalne[i] << " ";
		cout<< "\n";
		for (int i=1; i<=n; i++)
			cout<< wolne[i] << " ";
		cout<< "\n";*/
	}
	cout<< ilosc << "\n";
	for (int i=1; i<=n; i++) {
		if (zrealizowane[i] == 1)
			cout<< i << " ";
	}
	return 0;
}
