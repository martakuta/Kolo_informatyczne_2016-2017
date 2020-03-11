#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int odl[10*1000+5];
int odw[10*1000+5];
vector <pair <int, int> > G[10*1000+50];
int n;
const int inf = 1000*1000*1000;
void dijkstra () {
	for (int i=1; i<=2*n; i++)
		odl[i] = inf;
	odl[1] = 0;
	priority_queue <pair < int, int> > q;
	q.push(make_pair(0, 1));
	while (!q.empty()) {
		int cost = -q.top().first;
		int u = q.top().second;
		q.pop();
		if (odw[u] == 1)
			continue;
		odw[u] = 1;
		for (int i=0; i<G[u].size(); i++) {
			int x = G[u][i].second;
			if (G[u][i].first + cost < odl[x]) {
				odl[x] = G[u][i].first + cost;
				q.push(make_pair(-odl[x], x));
			}
		}
	}
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, a, b, c, cena;
	cin>> n;
	for (int i=1; i<=n; i++) {
		cin>> cena;
		G[i].push_back(make_pair(cena/2, n+i));
	}
	cin>> m;
	for (int i=0; i<m; i++) {
		cin>> a >> b >> c;
		G[a].push_back(make_pair(c, b));
		G[a+n].push_back(make_pair(c, b+n));
//		G[a].push_back(make_pair(cena[a]/2, a+n));
	}
/*	for (int i=0; i<=2*n; i++) {
		for (int j=0; j<G[i].size(); j++)
			cout<< G[i][j].first << "-" << G[i][j].second << " ";
		cout<< "\n";
	} */
	dijkstra();
//	for (int i=0; i<=2*n; i++)
//		cout<< odl[i] << " ";
	cout<< odl[n+1];
	return 0;
}
