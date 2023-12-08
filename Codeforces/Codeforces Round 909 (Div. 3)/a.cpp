#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
  int n; cin >> n;
  if(n%3 == 0) cout << "Second\n";
  else cout << "First\n";
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
