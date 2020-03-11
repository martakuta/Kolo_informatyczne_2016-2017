#include <bits/stdc++.h>
using namespace std;

vector <int> G[100*1000+5];
int indeg[100*1000+5];
queue <int> q;
queue <int> rozw;

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin>> n >> m;
	for (int i=0; i<m; i++) {
		int a, b;
		cin>> a >> b;
		G[a].push_back(b);
	}
	for (int i=1; i<=n; i++) {
		for (int y=0; y<G[i].size(); y++)
			indeg[G[i][y]] ++;
	}
	for (int i=1; i<=n; i++) {
		if (indeg[i] == 0)
			q.push(i);
	}
	if (q.size() > 1) {
		cout<< "NIE";
		return 0;
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i=0; i<G[v].size(); i++) {
			indeg[G[v][i]] --;
			if (indeg[G[v][i]] == 0)
				q.push(G[v][i]);
			if (q.size() > 1) { //czyli jest wiecej niz jeden sposob posortowania
				cout<< "NIE";
				return 0;
			}
		}
		rozw.push(v);
	}
	if (rozw.size() != n) {
		cout<< "NIE";
		return 0;
	}
	cout<< "TAK\n";
	while (!rozw.empty()) {
		int v = rozw.front();
		cout<< v << " ";
		rozw.pop();
	}
	return 0;
}
