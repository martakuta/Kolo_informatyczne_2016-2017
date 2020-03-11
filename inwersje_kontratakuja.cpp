#include <iostream>
using namespace std;
int wynik=0;
int A[60*1000+5], B[60*1000+5];
void merge (int p, int q, int r) {
    int i=p, j=q+1, s=p;
    while (i<=q && j<=r) {
        if (A[i] <= A[j]) {
            B[s] = A[i];
            i++;
        }
        else {
        	B[s] = A[j];
        	wynik += q+1-i;
		j++;
        }
        s++;
    }
    /* Skonczyl sie ktorys z ciagow: A[p..q] lub A[q+1..r]. Nalezy ogon
     drugiego ciagu przepisac do tablicy B na pozycje s+1..r */
    while (i<=q) {
        B[s] = A[i];
        i++;
        s++;
    }
    while (j <= r) {
        B[s] = A[j];
        j++;
        s++;
    }
    /* Teraz pozostaje tylko przepisac wynik-posortowany ciag z tablicy B
     do tablicy A                                                      */
    for (int i=p; i<=r; i++)
        A[i] = B[i];
}
void mergesort(int p, int r) {
    if (p == r) return;
    int q = (p + r)/2;
    mergesort(p, q);
    mergesort(q + 1, r);
    merge(p, q, r);
}
int main() {
    int n;
    cin>> n;
    for (int i=0; i<n; i++)
        cin>> A[i];
    mergesort(0, n - 1);
    cout<< wynik;
    return 0;
}
