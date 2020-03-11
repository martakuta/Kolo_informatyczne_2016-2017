#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair

multiset <pair <int, int> > s;
multiset <pair <int, int> >::iterator it;
long long T[250*1000+5];
bool biore[250*1000+5];

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b;
	cin>> n;
	long long spwar=0, spil=0; // sprzedane wartosc, sprzedane ilosc
	for (int i=1; i<=n; i++) {
		cin>> a;
		T[i] = a + T[i-1];
	}
	for (int i=1; i<=n; i++) {
		cin>> b;
		if (b < T[i] - spwar) {
			//biore to zamowienie
			spil ++;
			spwar += b;
			biore[i] = 1;
			s.insert(mp(b, i));
		} else {
			if (s.empty())
				continue;
			it = s.end();
			it--;
			if ((*it).f > b) {
				biore[(*it).s] = 0;
				biore[i] = 1;
				spwar = spwar - (*it).f + b;
				s.erase(it);
				s.insert(mp(b, i));
			}			
		}
	}
	cout<< spil << "\n";
	for (int i=1; i<=n; i++) {
		if (biore[i] == 1)
			cout<< i << " ";
	}
	return 0;
}
