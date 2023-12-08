#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
  int n, k, x; cin >> n >> k >> x;
  int sum0 = ((1+k)*k)/2;
  int sum1 = ((n+n-k+1)*k)/2;
  if(sum0 <= x && x <= sum1){
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
