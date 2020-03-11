#include<iostream>
#include <iomanip>
using namespace std;
typedef long double LD;
LD a[7];
LD w(LD x){
	return ((((a[5]*x + a[4])*x + a[3])*x + a[2])*x + a[1])*x +a[0];
}
LD szuk(){
	LD b=-1000,e=1000,sr;
	while( b<e-0.0000001){
		sr=(b+e)/2;
		if(w(sr)*w(e)>0)
			e=sr;
		else
			b=sr;
	}
	return b;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=5;i>=0;i--){
		cin >> a[i];
	}
	cout <<setprecision(7)<<fixed<< szuk() << '\n';
	return 0;
}