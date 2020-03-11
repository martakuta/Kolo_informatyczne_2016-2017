#include <iostream>
#include <algorithm>
using namespace std;
pair <int, int>  T[1000*1000+5];
int main () {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n, w;
	cin>> n >> w;
	for (int i=0; i<n; i++) {
		cin>> T[i].first;
		T[i].second = i;
	}
	sort (T, T+n);
	int ost= -1000*1000*1000-5, skal=0;
	for (int i=0; i<n; i++) {
		if (T[i].first != ost) {
			ost = T[i].first;
			skal++;
		}
		T[i].first = skal;
	}
	int maxdlugosc=0;
	int p=0, k=0, wartosc=1;
	while (k<n) {
		int polainne, polatakie=-1, dlugosc;
		while (T[k].first == wartosc) {
			polainne= T[k].second - T[p].second -polatakie -1;
			if (polainne == 0 && T[k].second - T[p].second == 1 && polatakie == 0) {
				dlugosc= w+2;
			} else if (polainne == 0 && polatakie == -1) {
				dlugosc= w+1;
			} else if (polainne<=w) {
				dlugosc= w + polatakie +2;
			} else
				dlugosc= w+1;
                        if (dlugosc > maxdlugosc)
                                maxdlugosc = dlugosc;
			if (polainne <= w) {
				k++;
				polatakie++;
			} else {
				p++;
				polatakie--;
			}
		}
		p=k;
		wartosc = T[p].first;
	}
	if (maxdlugosc> n)
		cout<< n;
	else
		cout<< maxdlugosc;
	return 0;
}
