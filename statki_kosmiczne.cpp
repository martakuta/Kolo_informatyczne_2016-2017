#include <iostream>
#include <algorithm>
using namespace std;
long long B[1005], K[1005], Z[1005], P[1005];
void merge (long long T[], int p, int q, int r) {
    int i=p, j=q+1, s=p;
    while (i<=q && j<=r) {
        if (T[i] < T[j]) {
            P[s] = T[i];
            i++;
        }
        else {
            P[s] = T[j];
            j++;
        }
        s++;
    }
    while (i<=q) {
        P[s] = T[i];
        i++;
        s++;
    }
    while (j <= r) {
        P[s] = T[j];
        j++;
        s++;
    }
    for (int i=p; i<=r; i++)
        T[i] = P[i];
}
void mergesort(long long T[], int p, int r) {
    if (p == r) return;
    int q = (p + r)/2;
    mergesort(T, p, q);
    mergesort(T, q + 1, r);
    merge(T, p, q, r);
}
int main () {
	ios::sync_with_stdio(0);
	long long pb, pk, pz, fb, fk, fz, ilosc=0; //p-paliwo, f-fabryka, b-Bajtek, k-Kajtek, z-Zajtek
	cin>> pb >> pk >> pz;
	cin>> fb;
	for (int i=1; i<=fb; i++) {
		cin>> B[i];
		B[i] *= pb;	
	}
	mergesort (B, 1, fb);
	B[0] = 0;
        cin>> fk;
        for (int i=1; i<=fk; i++) {
                cin>> K[i];
                K[i] *= pk;
        }
	mergesort (K, 1, fk);
	K[0] = 0;
        cin>> fz;
        for (int i=1; i<=fz; i++) {
                cin>> Z[i];
                Z[i] *= pz;
        }
	mergesort (Z, 1, fz);
	Z[0] = 0;
	long long maxi = ((B[fb] + K[fk] + Z[fz]) /2) +1;
	for (int i=1; i<=fb; i++) {
		for (int j=1; j<=fk; j++) {
			long long brak = maxi - B[i] - K[j];
			int p=0, k=fz+1;
                        while (p+1<k) {
      	                	long long sr = (p+k)/2;
                      		if (Z[sr] < brak)
               	        	        p=sr;
       	                        else
	                                k=sr;
       	                }
                        ilosc += fz+1-k;
		}
	}
	cout<< ilosc;
	return 0;
}
