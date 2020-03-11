#include <bits/stdc++.h>
using namespace std;
const int inf=200*1000*1000;
int T[inf+3];
int p[inf+3];
int ile[260];

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i=2; i<=inf; i++) {
		if (T[i] == 0) {
			for (int j=1; i*j<=inf; j++)
				T[i*j] = i;
		}
	}
//	for (int i=0; i<100; i++)
//		cout<< i << ": " << T[i] << "\n";
	for (int i=2; i<=inf; i++) {
		if (T[i] != i)  {//czyli jest liczba zlozona
			p[i] = p[i-1]+1;
			if (ile[p[i]] == 0) {
				ile[p[i]] = i;
			}
		}
	}
	for (int i=0; i<248; i++)
		cout<< ile[i] << ", ";

	return 0;
}
