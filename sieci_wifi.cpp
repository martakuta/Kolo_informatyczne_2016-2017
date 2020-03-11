#include <bits/stdc++.h>
using namespace std;

int sale[100*1000+5];

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testy;
	cin>> testy;
	for (int t=0; t<testy; t++) {
		int n, m;
		cin>> n >> m;
		cout<< setprecision(1) << fixed;
		for (int i=0; i<m; i++)
			cin>> sale[i];
		sort (sale, sale + m);
		if (n == 0) {
			cout<< sale[m-1] << "\n";
			continue;
		}
		double p=-1, k= (double)sale[m-1]+1;
		while (p+0.05<k) {
			int routery = 1;
			double dokad;
			double d = (p+k)/2;
			dokad = (double)sale[0] + d + d;
//			cout<< d << "\n";
//			cout<< setprecision(2) << fixed << "0 " << routery << " "<< dokad << "\n";
			for (int j=1; j<m; j++) {
				if ((double)sale[j] > dokad) {
					routery++;
					dokad = (double)sale[j] + d + d;
				}
//				cout<< setprecision(2) << fixed << j << " " << routery << " " << dokad << "\n";
			}
			if (routery > n)
				p = d;
/*			else if (routery == n && dokad >= sale[m-1])
				k = d;
			else if (routery == n)
				p = d;*/
			else
				k = d;
//			cout<< setprecision(2) << fixed << p << " " << k << "\n";
				
		}
		cout<< k << "\n";
	}
	return 0;
}
