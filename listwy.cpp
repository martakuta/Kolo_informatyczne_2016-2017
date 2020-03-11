#include <bits/stdc++.h>
using namespace std;

const int M = 8;
vector <int> G[2000*1000+5];
bool odw[1000*1000+5];
int d[2*M];
int listwy[1000*1000+5];
int dane[1000*1000+5];

void zmieniaj (int v) {
	v = v + M-1;
	if (d[v] == 0 && listwy[v] == 0) //czyli jesli sie nie swiecila ale jest wlaczona
		d[v] = 1; //to zaczyna sie swiecic
	else
		d[v] = 0;
	while (v > 0) {
		v /= 2;
		d[v] = d[2*v] + d[2*v+1];
	}
}

void dfs (int v) {
	odw[v] = 1;
	for (int i=0; i<G[v].size(); i++) {
		if (odw[G[v][i]] == 0 && listwy[G[v][i]] == 0) //czyli jesli jeszcze jej nie odwiedzilismy oraz jest wlaczona
			dfs(G[v][i]);
	}
}		

int main () {
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin>> n >> k;
	for (int i=1; i<=n; i++) {
		int a;
		cin>> a;
		if (a < 0) {
			G[n-a].push_back(i);
			dane[i] = n-a;
		} else {
			G[a].push_back(i);
			dane[i] = a;
		}
	}
	for (int i=M; i<M+n; i++)
		d[i] = 1;
	for (int i=M-1; i>0; i--)
		d[i] = d[2*i] + d[2*i+1];
	int q;
	cin>> q;
	for (int l=0; l<q; l++) {
		int zmien;
		cin>> zmien;
		int ojciec = dane[zmien];
		cout<< "zmien=" << zmien << " ojciec=" << ojciec << " " << listwy[zmien] << " ";
		if (listwy[zmien] == 0) { //listwa byla wlaczona, wylaczamy ja
			listwy[zmien] = 1;
			int ilsyn = G[ojciec].size();
			for (int i=0; i<ilsyn; i++) {
				if (G[ojciec][i] == zmien) {
					G[ojciec][i] = G[ojciec][ilsyn-1];
					cout<< "stara dlugosc" << G[ojciec].size() << " ";
					G[ojciec].pop_back();
					cout<< "nowa dlugosc" << G[ojciec].size() << "\n";
				}
			}
			cout<< "\nnowy wektor ojca: ";
			for (int i=0; i<G[ojciec].size(); i++)
				cout<< G[ojciec][i] << " ";
			cout<< "\n";
		} else { //listwa byla wylaczona, wlaczamy ja
			listwy[zmien] = 0;
			G[ojciec].push_back(zmien);
			cout<< "\nnowy wektor ojca: ";
			for (int i=0; i<G[ojciec].size(); i++)
				cout<< G[ojciec][i] << " ";
			cout<< "\n";
		}
		int gniazdko = ojciec;
		while (gniazdko <= n)
			gniazdko = dane[gniazdko];
		dfs(gniazdko);
		for (int i=1; i<=n; i++) {
			if (odw[i] != d[i+M-1])
				zmieniaj(i);
		}
		cout<< d[1] << "\n";
		for (int i=1; i<16; i++)
			cout<< d[i] << " ";
		cout<< "\n";
		for (int i=1; i<=n; i++)
			cout<< odw[i] << " ";
		cout<< "\n";
		for (int i=1; i<=n; i++)
			cout<< listwy[i] << " ";
		cout<< "\n";
	}
	return 0;
}
