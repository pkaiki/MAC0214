#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
  int n; cin >> n;
  int q; cin >> q;

  for(int i=1; i<n; i++){
    cout << i << ' ' << i+1 << '\n';
  }

  int cur = n-1;
  int u = n, v = n-1;
  for(int i=0; i<q; i++){
    int d; cin >> d;
    if(cur == d){
      cout << "-1 -1 -1\n";
      continue;
    }
    cout << u << ' ' << v << ' ' << d <<  '\n';
    v = d;
    cur = d;
  }
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
