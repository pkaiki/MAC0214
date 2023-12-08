#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
  int n, m; cin >> n >> m;
  int sum = 0;
  for(int i=0; i<60; i++){
    n %= m;
    if(n == 0) break;
    sum += n;
    n *= 2;
  }
  
  if(n != 0) cout << -1 << '\n';
  else cout << sum << '\n';
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
