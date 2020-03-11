#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector <int> G[5005];
pair < pair<int, int>, pair<int, int> > przygody[1000*1000+5];
bool odp[1000*1000];
int parzodl[5005];
int nieparzodl[5005];
bool parzodw[5005];
bool nieparzodw[5005];
const int inf = 1000*1000*1000+5;

void bfs (int v) {
	parzodw[v] = 1;
	parzodl[v] = 0;
	queue <pair <int, int> > q;
	q.push(make_pair(v, 1));
	while (!q.empty()) {
		if (q.front().s == 1) {
			int u = q.front().f;
			q.pop();
			for (int i=0; i<G[u].size(); i++) {
				nieparzodw[G[u][i]] = 1;
				if (nieparzodl[G[u][i]] > parzodl[u] +1) {
					nieparzodl[G[u][i]] = parzodl[u] +1;
					q.push(make_pair(G[u][i], 0));
				}
			}
		} else {
			int u = q.front().f;
			q.pop();
			for (int i=0; i<G[u].size(); i++) {
				parzodw[G[u][i]] = 1;
				if (parzodl[G[u][i]] > nieparzodl[u] +1) {
					parzodl[G[u][i]] = nieparzodl[u] +1;
					q.push(make_pair(G[u][i], 1));
				}
			}
		}
	}
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k, a, b, d;
	cin>> n >> m >> k;
	for (int i=0; i<m; i++) {
		cin>> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i=0; i<k; i++) {
		cin>> przygody[i].f.f >> przygody[i].f.s >> przygody[i].s.f;
		przygody[i].s.s = i;
	}
	sort (przygody, przygody+k);
	int p=0, r=0;
	while (p < k) {
		while (przygody[r].f.f == przygody[r+1].f.f) 
			r++;
		for (int j=1; j<=n; j++) {
			parzodl[j] = inf;
			nieparzodl[j] = inf;
			parzodw[j] = 0;
			nieparzodw[j] = 0;
		}
		a= przygody[p].f.f;
		bfs(a);
		for (int y=p; y<=r; y++) {
			b= przygody[y].f.s;
			d= przygody[y].s.f;
			if (G[a].size() == 0 || G[b].size() == 0) {
				odp[przygody[y].s.s] = 0;
				continue;
			}
			if (d%2 == 0) {
				if (parzodl[b] > d)
					odp[przygody[y].s.s] = 0;
				else
					odp[przygody[y].s.s] = 1;
			} else {
				if (nieparzodl[b] > d)
					odp[przygody[y].s.s] = 0;
				else
					odp[przygody[y].s.s] = 1;
			}
		}
		p = r+1;
		r++;
	}

	for (int i=0; i<k; i++) {
		if (odp[i] == 0)
			cout<< "NIE\n";
		else
			cout<< "TAK\n";
	}
	return 0;
}
