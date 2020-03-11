#include <iostream>
#include <algorithm>
using namespace std;
long long n, a, b, c, x;
int main () {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin>> n;
	for (int i=0; i<n; i++) {
                cin>> x;
		c=b;
		b= max(a, b);
		a=c+x;
	}
	cout<< max(a, b);
	return 0;
}

