#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> freq(51, 0);
	vector<int> S[n];
	vector<int> sets_that_have[51];
	for(int i=0; i<n; i++){
		int k; cin >> k;
		for(int j=0; j<k; j++){
			int x; cin >> x;
			S[i].push_back(x);
			freq[x]++;
			sets_that_have[x].push_back(i);
		}
	}

	int sz = 0;

	for(int i=1; i<=50; i++){
		if(freq[i]) sz++;
	}
	
	int original_sz = sz;
	int maxx = 0;

	for(int i=1; i<=50; i++){
		for(auto st : sets_that_have[i]){
			for(auto x : S[st]){
				freq[x]--;
				if(freq[x] == 0){
					sz--;
				}
			}
		}

		if(sz != original_sz){
			maxx = max(sz, maxx);
		}

		for(auto st : sets_that_have[i]){
			for(auto x : S[st]){
				freq[x]++;
			}
		}
		sz = original_sz;
	}
	cout << maxx << '\n';
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
