#include <bits/stdc++.h>
using namespace std;

long long p;

long long silnia (long long a) {
	if (a == 1)
		return 1;
	else
		return (a * silnia(a-1)) %p;
}

long long potega (long long a, long long b) {
	a %= p;
	if (b==1)
		return a;
	else if (b%2 == 0)
		return (potega (a*a, b/2))%p;
	else
		return (a * potega (a*a, b/2))%p;
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, m;
	cin>> n >> m >> p;
	long long licznik = silnia (n+m);
	long long a = (silnia(n) * silnia(m))%p;
	long long mianownik = potega (a, p-2);
	long long wynik = (licznik * mianownik)%p;
	cout<< wynik;
	return 0;
}
