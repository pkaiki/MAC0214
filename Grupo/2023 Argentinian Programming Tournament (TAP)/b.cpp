#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 56;

char M[N][N];

void solve(){
	int n; cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> M[i][j];

	int cnt = 0;		

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(M[i][j] == 'N')
				if(j+1 < n && M[i][j+1] == 'N'){
					cnt++;
					M[i][j] = 'B';
					M[i][j+1] = 'B';
				}
					
	cout << cnt << '\n';
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}
