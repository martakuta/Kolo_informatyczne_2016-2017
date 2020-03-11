#include <bits/stdc++.h>
using namespace std;

vector <int> G[100*1000+5];
int indeg[100*1000+5];
queue <int> q;
int rozw[100*1000+5];
int r=0;

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
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i=0; i<G[v].size(); i++) {
			indeg[G[v][i]] --;
			if (indeg[G[v][i]] == 0)
				q.push(G[v][i]);
		}
		rozw[r] = v;
		r++;
	}
	int 
	for (int i=0; i<r; i++)
		cout<< 	rozw[i] << " ";
	
	return 0;
}
