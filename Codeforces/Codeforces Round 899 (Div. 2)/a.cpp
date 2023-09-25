#include <bits/stdc++.h>
#define int long long
using namespace std;

const int oo = 1e17;

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++){
		int minn = oo;
		for(int j=1; j<=2*n+10; j++){
			if(a[i]== j) continue;
			if(i == 0){
				minn =  min(j, minn);
			}
			if(i > 0 && b[i-1] < j){
				minn = min(j, minn);
			}
		}
		b[i] = minn;
	}
	cout << b[n-1] << '\n';
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
