#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
  int n; cin >> n;
  map<pair<int,int>, int> mp;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    int exp = x;
    while(x%2 == 0){
      x /= 2;
      exp--;
    }
    mp[{exp, x}]++;
  }

  int sum = 0;

  for(auto [par, val] : mp){
    sum += (val * (val-1))/2;
  }

  cout << sum << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
