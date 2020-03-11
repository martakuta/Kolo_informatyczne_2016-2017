#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define f first
#define s second
vector < pair <int, int> > G[100*1000+5];
long long odl[100*1000+5];
bool odw[100*1000+5];
bool skrzyz[100*1000+5];
const int inf = 1000*1000*1000;
int n;
void dijkstra (int v) {
	for (int i=1; i<=n; i++)
		odl[i] = inf;
	odl[v] = 0;
	priority_queue < pair <int, int> > q;
	q.push(make_pair(0, v));
	while (!q.empty()) {
		int cost= -q.top().f;
		int u= q.top().s;
		q.pop();
		if (odw[u] == 1)
			continue;
		odw[u] = 1;
		for (int i=0; i<G[u].size(); i++) {
			int w= G[u][i].s;
			if (cost + G[u][i].f < odl[w]) {
				odl[w] = cost + G[u][i].f;
				q.push(make_pair(-odl[w], w));
			}
		}
	}
}
void skrzyzowania (int w, int najm) {
	for (int i=0; i<G[w].size(); i++) {
		if (G[w][i].f + odl[G[w][i].s] == najm) {
			skrzyz[w] = 1;
			skrzyzowania (G[w][i].s, odl[G[w][i].s]);
		}
	}
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int m, a, b, c;
	cin>> n >> m;
	for (int i=0; i<m; i++) {
		cin>> a >> b >> c;
		G[a].push_back(make_pair(c, b));
		G[b].push_back(make_pair(c, a));
	}
	dijkstra(n);
	int najm = odl[1];
	skrzyzowania (1, najm);
	for (int i=1; i<=n; i++) {
		if (skrzyz[i] == 1)
			cout<< i << "\n";
	}
	cout<< n; 
	return 0;
}
