#include <bits/stdc++.h>
using namespace std;

vector <int> G[1000*1000+5];
int w[1000*1000+5];
int dp[1000*1000+5][2];
bool odw[1000*1000+5];

void dfs(int v) {
	cout<< "dfs" << v << "\n";
	odw[v] = 1;
	int minus, plus;
	for (int i=0; i<G[v].size(); i++) {
		if (odw[G[v][i]] == 0)
			dfs(G[v][i]);
		minus = max(dp[v][0], dp[G[v][i]][0]);
		plus = max(dp[v][1], dp[G[v][i]][1]);
	}
	int roz = w[v] - minus + plus;
	if (roz > 0) {
		dp[v][0] += roz;
	} else {
		dp[v][1] -= roz;
	}
	cout<< v << ": " << minus << " " << plus << " " << roz << " " << dp[v][0] << " " << dp[v][1] << "\n";
	cout<< "w" << v << "\n";
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>> n;
	for (int i=1; i<n; i++) {
		int a, b;
		cin>> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i=1; i<=n; i++)
		cin>> w[i];
	dfs(1);
	for (int i=1; i<=n; i++) 
		cout<< i << ": " << dp[i][0] << " " << dp[i][1] << "\n";
	cout<< "\n";
	for (int i=1; i<=n; i++) {
		cout<< i << ": ";
		for (int j=0; j<G[i].size(); j++)
			cout<< G[i][j] << " ";
		cout<< "\n";
	}
	return 0;
}
