#include <bits/stdc++.h>
using namespace std;

struct kraw {
	int w, a, b;
};

int wys[100*1000+5];
int rep[100*1000+5];
kraw kr[300*1000+5];

bool comp0 (kraw x, kraw y) {
	return x.w < y.w;
}

int fin (int v) {
	if (rep[v] == v)
		return v;
	else return rep[v] = fin (rep[v]);
}

void onion (int a, int b) {
	rep[fin(b)] = fin(a);
}

int main () {
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin>> n >> m;
	for (int i=1; i<=n; i++) {
		cin>> wys[i];
		rep[i] = i;
	}
	for (int i=0; i<m; i++) {
		int a, b;
		cin>> a >> b;
		kr[i].a = a;
		kr[i].b = b;
		kr[i].w = max(wys[a], wys[b]);
	}
	sort(kr, kr+m-1, comp0);
//	for (int i=0; i<=m; i++) 
//		cout<< i << ": " << kr[i].w << " " << kr[i].a << " " << kr[i].b << "\n";
	int wynik=0;
	int x=-1;
	onion (kr[0].a, kr[0].b);
	while (rep[1] != rep[n]) {
//		cout<< "while: " << fin[1] << " " << fin[n] << "\n";
		while (kr[x+1].w == wynik) {
			x++;
			onion (kr[x].a, kr[x].b);
			for (int i=1; i<=x; i++)
				fin(i);
		}
//		cout<< x << "\n";
//		for (int i=1; i<=n; i++)
//			cout<< rep[i] << " ";
//		cout<< "\n";
//		cout<< wynik << "\n";
		x++;
		wynik = kr[x].w;
	}
	x--;
	wynik = kr[x].w;
	cout<< wynik << "\n";
// z jakiegos powodu po polaczeniu onion dwoch punktow (nalezacych do jednej krawedzi) nie zmienia sie numer reprezentanta w calej spojnej a jedynie w laczonych krawedziach
	return 0;
}
