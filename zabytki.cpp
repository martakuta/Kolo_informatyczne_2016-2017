#include <iostream>
#include <vector>
using namespace std;
vector <int> G[1000*1000+5];
int w[2][1000*1000+5];
bool odw[1000*1000+5];
bool cykl[1000*1000+5];
int n, m;
bool dfs (int v) {
	odw[v]=1;
	cykl[v]=1;
	for (int i=0; i<G[v].size(); i++) {
		if (cykl[G[v][i]] == 1) {
			return 1;
		}
		if (odw[G[v][i]] == 0) {
			if (dfs(G[v][i]) == 1)
				return 1;
		}
		//cykl[G[v][i]]=0;
	}
	cykl[v]=0; //added
	return 0;
}
bool czyjestcykl (int s) {
	for (int i=1; i<=s; i++)
		G[w[0][i]].push_back(w[1][i]);
	for (int i=1; i<=n; i++) {
		if (odw[i] == 0) {
			if (dfs(i) == 1) {
				return 1;
			}
//			for (int x=1; x<=n; x++)
//				cykl[x]=0;
		}
	}
	return 0;
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int a, b;
	cin>> n >> m;
	for (int i=1; i<=m; i++) {
		cin>> w[0][i]  >> w[1][i];
	}
	int p=0, k=m+1;
	while (p+1<k) {
		int s=(p+k)/2;
		if (czyjestcykl(s) == 0)
			p=s;
		else k=s;
		for (int i=1; i<=n; i++)
			G[i].clear();
		for (int i=1; i<=n; i++) {
			cykl[i]=0;
			odw[i]=0;
		}
	}
	if (k == m+1)
		cout<< "NIE";
	else
		cout<< k;
	return 0;
}