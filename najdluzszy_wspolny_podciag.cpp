#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005];
int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string a, b, w;
	cin>> a >> b;
	int da = a.size(), db = b.size();
	for (int i=1; i<=db; i++) {
		for (int j=1; j<=da; j++) {
			if (a[j-1] == b[i-1]) {
				dp[i][j]  = dp[i-1][j-1] + 1;
			} else dp[i][j] = max ( dp[i][j-1], dp[i-1][j]);
		}
	}
	int s= dp[db][da];
	int x=db; 
	int y=da;
	while (s>0) {
		if (dp[x-1][y] == s)
			x--;
		else if (dp[x][y-1] == s)
			y--;
		else {
			y--;
			x--;
			s--;
			w = a[y] + w;
		}
	}

	cout<< dp[db][da] << "\n" << w << "\n";
	
	return 0;
}
