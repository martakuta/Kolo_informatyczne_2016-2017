#include <iostream>
using namespace std;
int A[1000*1000+5], B[1000*1000+5];
int main () {
	ios::sync_with_stdio(0);
	int n, m, a, b;
	cin>> n >> m;
	for (int i=1; i<=n; i++)
		cin>> A[i];
	for (int l=1; l<=m; l++)
		cin>> B[l];
	for (int x=1; x<=n; x++)
		 A[x] += A[x-1];
	for (int x=1; x<=m; x++)
		 B[x] += B[x-1];
	int zap, dzien, mies;
	string c;
	cin>> zap;
	for (int j=0; j<zap; j++) {
		cin>> dzien >> mies >> c;
		if (c=="A") {
			int droku = A[mies-1] + dzien;
			int p=-1, k=m+1;
			while (p+1 < k) {
				int sr = (p+k)/2;
				if (B[sr] < droku)
					p= sr;
				else k= sr; //szukany dzien jest w obrebie wartosci na polu k
			}
			int dzien2 = droku - B[k-1];
			int mies2 = k;
			cout<< dzien2 << " " << mies2 << "\n";
		} else {
			int droku = B[mies-1] + dzien;
			int p=-1, k=n+1;
			while (p+1 < k) {
				int sr = (p+k)/2;
				if (A[sr] < droku)
					p = sr;
				else k = sr; //szukany dzien jest w obrebie wartosci na polu k
			}
			int dzien2 = droku - A[k-1];
			int mies2 = k;
			cout<< dzien2 << " " << mies2 << "\n";
		}
	}
	return 0;
}
