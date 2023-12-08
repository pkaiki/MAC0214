#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
  int n; cin >> n;
  for(int i=0; i<n; i++){
    cout << 1000 + i << ' ';
  }
  cout << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
