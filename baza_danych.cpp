#include <iostream>
#include <map>
using namespace std;
map <string, int> m;
map <string, int>::iterator it;
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, pieniadze;
	string pesel;
	cin>> n;
	for (int i=0; i<n; i++) {
		cin>> pesel >> pieniadze;
		m[pesel] += pieniadze;
		if (m[pesel] < 0) {
			cout<< "NIE\n";
			m[pesel] -= pieniadze;
		}
		else
			cout<< m[pesel] << "\n";
	}
	return 0;
}
