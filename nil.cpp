#include <iostream>
#include <vector>
using namespace std;
vector <int> G[1000*1000+5];
int ryby[1000*1000+5];
long long maxi[1000*1000+5];
void plyn (int v, int poprz) {
	maxi[v] = ryby[v] + maxi[poprz];
	for (int i=0; i<G[v].size(); i++) {
		if (maxi[G[v][i]]==-1) {
			plyn(G[v][i], v);
		}
	}
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int a, b, rozwidlenia;
	cin>> rozwidlenia;
	for (int i=1; i<=rozwidlenia; i++) {
		cin>> ryby[i];
		maxi[i] = -1;
	}
	maxi[0]=0;
	for (int i=1; i<rozwidlenia; i++) {
		cin>> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	plyn(1, 0);
	long long najw=0;
	for (int i=1; i<=rozwidlenia; i++) {
		if (maxi[i]>najw)
			najw = maxi[i];
	}
	cout<< najw;
	return 0;
}
