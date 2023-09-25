#include <bits/stdc++.h>
#define int long long
using namespace std;

set<int> Ef;

void evaluate(int x){
	while(true){
		auto it_mod = Ef.lower_bound(-x);
		if(it_mod == Ef.end()) break;
		int mod = -(*it_mod);
		x %= mod;
	}
	cout << x << ' ';
}

void solve(){
	int n, m; cin >> n >> m;
	vector<int> A(n);
	vector<int> E;
	for(int i=0; i<n; i++) cin >> A[i];
	int x; cin >> x;
	E.push_back(x);

	for(int i=1; i<m; i++){
		int x; cin >> x;
		if(E[E.size()-1] <= x) continue;
		E.push_back(x);
	}
	
	for(int i=0; i<E.size(); i++) Ef.insert(-E[i]);

	for(int i=0; i<n; i++){
		evaluate(A[i]);
	}
	cout << '\n';
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}
