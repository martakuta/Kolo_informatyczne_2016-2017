#include <iostream>
#include <algorithm>
using namespace std;
pair <int, int> T[1000*1000+5];
int main () {
	ios::sync_with_stdio(0);
	int n, abajt, vbajt, abit, vbit;
	cin>> n >> abajt >> vbajt;
	for (int i=0; i<n; i++) {
		cin>> abit >> vbit;
		if (vbit <= vbajt)
			T[i].first = 2*1000*1000*1000+5; // czyli nigdy nie dogoni
		else
			T[i].first = (abajt - abit) / (vbit - vbajt);
		T[i].second = i+1;
	}
	sort (T, T+n);
	for (int i=0; i<n; i++) {
		if (T[i].first < i) {
			cout<< "GAME OVER";
			return 0;
		}
	}
	for (int i=0; i<n; i++)
		cout<< T[i].second << " ";
	return 0;
}
