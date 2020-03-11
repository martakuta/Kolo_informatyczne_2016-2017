#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <pair <int, int> > G[500*1000+5];
long long odl[500*1000+5];
bool odw[500*1000+5];
int n;
long long int inf = 1000*1000*1000*500LL;
void dijkstra () {
	for (int i=1; i<=n; i++)
		odl[i] = inf;
	odl[1] = 0;
	priority_queue <pair <long long, int> > q;
	q.push (make_pair(0, 1));
	while (!q.empty()) {
		int u= q.top().second;
		long long cost = -q.top().first;
		q.pop();
		if (odw[u] == 1)
			continue;
		odw[u] = 1;
		for (int i=0; i<G[u].size(); i++) {
			int w= G[u][i].second;
			if (cost + G[u][i].first < odl[w]) {
				odl[w] = cost + G[u][i].first;
				q.push(make_pair(-odl[w], w));
			}
		}
	}
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int m, a, b, w;
	cin>> n >> m;
	for (int i=0; i<m; i++) {
		cin>> a >> b >> w;
		G[a].push_back(make_pair (w, b));
		G[b].push_back(make_pair (w, a));
	}
	dijkstra();
	for (int i=1; i<=n; i++) {
		if (odl[i] == inf)
			cout<< "-1\n";
		else
			cout<< odl[i] << "\n";
	}
	return 0;
}
