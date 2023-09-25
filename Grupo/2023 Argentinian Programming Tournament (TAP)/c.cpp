#include <bits/stdc++.h>
#define int long long
using namespace std;

const int oo = 1e17;

void solve(){
	int n; cin >> n;
	vector<int> A(n);
	vector<int> B(n);
	for(int i=0; i<n; i++) cin >> A[i];
	for(int i=0; i<n; i++) cin >> B[i];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	reverse(B.begin(), B.end());
	int maxx = 0;
	int minn = oo;
	for(int i=0; i<n; i++){
		maxx = max(A[i] + B[i], maxx);
		minn = min(A[i] + B[i], minn);
	}
	cout << maxx - minn << '\n';
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}
