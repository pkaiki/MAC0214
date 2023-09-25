#include <bits/stdc++.h>
using namespace std;
 
void solve(){
	int n; cin >> n;
	vector<int> a(n);
	vector<int> b;
	for(int i=0; i<n; i++) cin >> a[i];
 
	int h = 0;
	for(int i=0; i<n; i++){
		int dif;
		int j;
		for(j=0; a[i] == a[i+j] && i+j < n; j++){
			h++;
		}
		if(i+j == n) dif = a[i];
		else dif = a[i] - a[i+j];
 
		for(int k=0; k<dif; k++){
			b.push_back(h);
			if(b.size() > a.size()){
				cout << "NO\n";
				return;
			}
		}
		i = i+j-1;
	}
 
	reverse(b.begin(), b.end());
 
	if(b.size() != a.size()){
		cout << "NO\n";
		return;
	}
 
	for(int i=0; i<n; i++){
		if(a[i] != b[i]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	return;
}
 
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--) solve();
}
 
