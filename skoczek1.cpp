#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int > G[1005*1005];
int odl[1005*1005];
char plansza[1005*1005];
int w;
void bfs (int v) {
	for (int i=0; i<=w; i++)
		odl[i]=1000*1000*1000+5;
	odl[v]=0;
	queue <int> q;
	q.push(v);
//	cout<< "kolejka: " << v << " ";
	while (!q.empty()) {
		int u=q.front();
		q.pop();
//		cout<< "u=" << u << "d" << G[u].size() << " ";
		for (int j=0; j<G[u].size(); j++) {
			int x=G[u][j];
//			cout<< "x=" << x << "ox" << odl[x] << "ou" << odl[u] << " ";
			if (odl[x]>odl[u]+1) {
				odl[x]=odl[u]+1;
				q.push(x);
//				cout<< x << " ";
			}
		}
	}
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n, m, a, b, s, k;
	string wiersz;
	cin>> n >> m >> a >> b;
	w=n*m;
	for (int i=1; i<=n; i++) {
		cin>> wiersz;
		for (int j=1; j<=m; j++) {
			if (wiersz[j-1] == 'S') s=(i-1)*m+j;
			if (wiersz[j-1] == 'K') k=(i-1)*m+j;
			plansza[(i-1)*m+j] = wiersz[j-1];
		}
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (plansza[(i-1)*m+j] != 'X') {
				if (plansza[(i-1-a)*m+j-b] != 'X' && (i-1-a)*m+j-b >0 && (i-1-a)*m+j-b <=n*m && j-b>0)
					G[(i-1)*m+j].push_back((i-1-a)*m+j-b);
			       if (plansza[(i-1-a)*m+j+b] != 'X' && (i-1-a)*m+j+b >0 && (i-1-a)*m+j+b <=n*m && j+b<=m)
                                        G[(i-1)*m+j].push_back((i-1-a)*m+j+b);
			       if (plansza[(i-1+a)*m+j-b] != 'X' && (i-1+a)*m+j-b >0 && (i-1+a)*m+j-b <=n*m && j-b>0)
                                        G[(i-1)*m+j].push_back((i-1+a)*m+j-b);
			       if (plansza[(i-1+a)*m+j+b] != 'X' && (i-1+a)*m+j+b >0 && (i-1+a)*m+j+b <=n*m && j+b<=m)
                                        G[(i-1)*m+j].push_back((i-1+a)*m+j+b);
			       if (plansza[(i-1-b)*m+j-a] != 'X' && (i-1-b)*m+j-a >0 && (i-1-b)*m+j-a <=n*m && j-a>0)
                                        G[(i-1)*m+j].push_back((i-1-b)*m+j-a);
			       if (plansza[(i-1-b)*m+j+a] != 'X' && (i-1-b)*m+j+a >0 && (i-1-b)*m+j+a <=n*m && j+a<=m)
                                        G[(i-1)*m+j].push_back((i-1-b)*m+j+a);
			       if (plansza[(i-1+b)*m+j-a] != 'X' && (i-1+b)*m+j-a >0 && (i-1+b)*m+j-a <=n*m && j-a>0)
                                        G[(i-1)*m+j].push_back((i-1+b)*m+j-a);
			       if (plansza[(i-1+b)*m+j+a] != 'X' && (i-1+b)*m+j+a >0 && (i-1+b)*m+j+a <=n*m && j+a<=m)
                                        G[(i-1)*m+j].push_back((i-1+b)*m+j+a);
			}
		}
	}
	bfs(s);
//	for (int i=0; i<=n*m; i++)
//		cout<< i << ": " << odl[i] << "  ";
	if (odl[k] == 1000*1000*1000+5)
		cout<<"NIE";
	else cout<< odl[k];
	return 0;

}
