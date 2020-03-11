#include <iostream>
#include <set>
using namespace std;
multiset <int> s;
multiset <int>::iterator it;
int main () {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n, wpis, suma=0, cena;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin>> wpis;
		if (wpis == 1) {
			cin>> cena;
			s.insert (cena);
			suma += cena;
		} else if (wpis == 2) {
			it = s.begin();
			cout<< *it << "\n";
			suma -= *it;
			s.erase(it);
		} else if (wpis == 3) {
			it = s.end();
			it--;
			cout<< *it << "\n";
			suma -= *it;
			s.erase(it);
		} else {
			cout<< suma << "/" << s.size() << "\n";
		}
	}
	return 0;
}
