#include <bits/stdc++.h>
using namespace std;

int T[500*1000+5]; // w tej tablicy mam ile wynosi najdluzszy prefiksosufiks dla slowa od poczatku do danego indeksu

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string slowo;
	cin>> slowo;
	int d = slowo.size();
	T[0] = 0;
	for (int i=1; i<d; i++) {
		int poprz = T[i-1];
		while (slowo[i] != slowo[poprz])
			poprz = T[poprz];
		T[i] = T[poprz] + 1;
//		if (slowo[i] == slowo[poprz])
//			T[i] = T[poprz] + 1;
//		else poprz = T[poprz];
	}
	for (int i=0; i<d; i++)
		cout<< T[i] << " ";
	cout<< "\n";
	return 0;
}
