#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
set <int> s;
set <int>::iterator it;
pair <int, int> tab[1000*1000+5];
int main () {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int m, n, wynik=0;
	cin>> m >> n;
	for (int i=1; i<=m; i++)
		s.insert(i);
	for (int i=0; i<n; i++)
		cin>> tab[i].first >> tab[i].second;
	sort (tab, tab+n);
	for (int i= n-1; i>=0; i--) {
		it = s.lower_bound(tab[i].second);
		if (*it >= tab[i].second) {
			wynik += tab[i].first;
			s.erase(it);
		}
	}
	cout<< wynik;
	return 0;
}
