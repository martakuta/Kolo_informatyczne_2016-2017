#include <bits/stdc++.h>
using namespace std;

char T[16*1000*1000+5];
int P[16*1000*1000+5];

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin>> n >> m;
	int s = n+m;
	for (int i=0; i<n; i++)
		cin>> T[i];
	T[n] = '#';
	for (int i=n+1; i<=s; i++)
		cin>> T[i];
	P[0] = 0;	
	for (int i=1; i<=s; i++) {
		int sprawdz = P[i-1];
		while (sprawdz > 0) {
			if (T[sprawdz] == T[i]) {
				P[i] = P[i-1] + 1;
				break;
			}
			else sprawdz = P[sprawdz-1];
		}
		if (sprawdz == 0 && T[0] == T[i])
			P[i] = 1;
	}
	priority_queue <int> q;
	for (int i=n+1; i<=s; i++) {
		if (P[i] == n)
			q.push(-(i-n-n+1));
	}
	while (!q.empty()) {
		int u = -q.top();
		cout<< u << "\n";
		q.pop();
	}
	return 0;
}
