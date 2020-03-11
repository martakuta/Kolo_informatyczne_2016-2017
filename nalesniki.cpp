#include <iostream>
#include <algorithm>
using namespace std;
int sn[2005], sm[2005];
int policzone[2005][2005];
const int inf= 1000*1000*1000;
int nalesnik (int n, int m) {
	if (n==0 && m==0)
		return 0;
	if (n<0 || m<0)
		return inf;
	if (policzone[n][m] != -1*inf)
		return policzone[n][m];
	int mini = min ( nalesnik(n-1, m), nalesnik(n, m-1) );
	policzone[n][m] = sn[n] + sm[m] - mini;
	return policzone[n][m];
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n, m, a;
	cin>> n >> m;
	for (int i=1; i<=n; i++) {
		cin>> a;
		sn[i] = sn[i-1] + a;
	}
	for (int i=1; i<=m; i++) {
		cin>> a;
		sm[i] = sm[i-1] + a;
	}
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=m; j++) 
			policzone [i][j] = -1 * inf;
	}
	policzone[0][0] = 0;
	cout<< nalesnik(n, m) << "\n";
	return 0;
}
