#include <bits/stdc++.h>
using namespace std;

vector <int> G[2000*1000+5];
int listwy[1000*1000+5];
bool odw[1000*1000+5];

void dfs (int v) {
	odw[v] = 1;
	for (int i=0; i<G[v].size(); i++) {
		if (odw[G[v][i]] == 0 && listwy[G[v][i]] == 0) //czyli jesli jeszcze nie bylam w danej sasiedniej listwie oraz jesli jest ona wlaczona
			dfs(G[v][i]);
	}
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin>> n >> k;
	for (int i=1; i<=n; i++) {
		int a;
		cin>> a;
		if (a < 0)
			G[n-a].push_back(i);
		else
			G[a].push_back(i);
	}
	int q;
	cin>> q;
	for (int l=0; l<q; l++) {
		int zmien;
		cin>> zmien;
		if (listwy[zmien] == 0)
			listwy[zmien] = 1; //1 czyli jest wylaczona OFF
		else
			listwy[zmien] = 0; //0 czyli jest wlaczona ON
		for (int i=1; i<=n; i++)
			odw[i] = 0;
		for (int g=n+1; g<=n+k; g++)
			dfs(g);
		int wlaczone = 0;
		for (int i=1; i<=n; i++)
			wlaczone += odw[i];
		cout<< wlaczone << "\n";
	}
	return 0;
}
