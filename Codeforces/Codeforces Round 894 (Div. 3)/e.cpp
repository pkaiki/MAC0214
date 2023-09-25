#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
void solve(){
	int n, m, d; cin >> n >> m >> d;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
 
	multiset<int> st;
	int sum = 0;
	int res = 0;
 
	for(int i=0; i<n; i++){
		if(st.size() < m && a[i] > 0){
			sum += a[i];
			st.insert(a[i]);
		}
		else{
			auto it = st.begin();
			int lower = *it;
			if(a[i] > lower){
				sum += a[i];
				sum -= lower;
				st.insert(a[i]);
				st.erase(it);
			}
		}
		res = max(res, sum-d*(i+1));
	}
	cout << res << '\n';
}
 
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--) solve();
}
