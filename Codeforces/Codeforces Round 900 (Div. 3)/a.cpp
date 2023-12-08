#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
  int n, k; cin >> n >> k;
  bool flg = false;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    if(x == k && flg == false){
      cout << "YES\n";
      flg = true;
    }
  }
  if(flg == false){
    cout << "NO\n";
  }
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
