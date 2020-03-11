#include <iostream>
#include <vector>
using namespace std;

vector <int> G[1000*1000+5];
int dane[1000*1000+5];
int ile[1000*1000+5];
bool odwiedzone[1000*1000+5];

void dfs (int v) {
	odwiedzone[v] = 1;
	for (int i=0; i<G[v].size(); i++) {
		if (odwiedzone[G[v][i]] == 0)
			dfs(G[v][i]);
		ile[v] += ile[G[v][i]];
	}
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin>> n >> k;
	for (int i=1; i<=n; i++) {
		cin>> dane[i];
		ile[i] = 1;
		G[dane[i]].push_back(i);
	}
	ile[0] = 1;

	dfs(0);

	for (int i=1; i<=n; i++) {
		if (ile[i] < k)
			cout<< "TAK\n";
		else
			cout<< "NIE\n";
	}
	return 0;
}
