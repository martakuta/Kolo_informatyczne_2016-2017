#include <bits/stdc++.h>
using namespace std;

int a[1000*1000+5];
int n;
const int inf = 2*1000*1000*1000+7;

int licz(double w) {
	double najn = (double)a[0] - w;
	for (int j=1; j<n; j++) {
		if (a[j] + w < najn) {
			najn = inf;
			break;
		} else
			najn = max ((double)a[j] - w, najn);
	}
//	cout<< "licz" << w << " " << najn << "\n";
	return najn;
}


int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>> n;
	cout<< setprecision(4) << fixed;
	for (int i=0; i<n; i++)
		cin>> a[i];
	double p=0, k=1000*1000+1;
	double e = 0.00000001;
	while (p+e <= k) {
//		cout<< p << " "<< k << "\n";
		double w = (p+k)/2;
		if (licz(w) == inf)
			p = w;
		else
			k = w;		
	}
	licz(p);
	cout<< p << "\n";
	double najw = (double)a[0] - p;
	cout<< najw << "\n";
	for (int j=1; j<n; j++) {
		najw = max (najw , a[j] - p);
		cout<< najw << "\n";
	}
	return 0;
}
