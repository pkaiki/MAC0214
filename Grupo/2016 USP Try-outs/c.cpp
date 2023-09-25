#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll oo = 1e17;

void solve(){
  ll h, w; cin >> h >> w;
  vector<ll> a(h);
  vector<ll> b(h);
  for(ll i=0; i<h; i++) cin >> a[i];  
  for(ll i=0; i<h; i++) cin >> b[i];  

  double min_dif = oo;

  for(ll i=0; i<h; i++){
    min_dif = min(min_dif, (double)w-a[i]-b[i]);
  }
  cout << min_dif/2 << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
 
