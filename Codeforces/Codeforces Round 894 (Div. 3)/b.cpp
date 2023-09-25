#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
void solve(){
	int n; cin >> n;
	vector<int> b(n);
	vector<int> a;
	for(int i=0; i<n; i++) cin >> b[i];
	a.push_back(b[0]);
	for(int i=1; i<n; i++){
		if(b[i-1] == 1) a.push_back(b[i]);
		else{
			a.push_back(1);
			a.push_back(b[i]);
		}
	}
	cout << a.size() << '\n';
	for(int i=0; i<a.size(); i++) cout << a[i] << ' '; cout << '\n';
}
 
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--) solve();
}
