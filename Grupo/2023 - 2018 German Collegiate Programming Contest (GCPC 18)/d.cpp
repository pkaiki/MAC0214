#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 0x3f3f3f3f3f3f3f3f;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  
  vector<ll> a(n);
  for(ll &i : a) cin >> i;

  if(n == 1){
    cout << a[0]+1 << "\n";
    return 0;
  }

  ll dif = 0, l = -INF, r = INF;
  for(int i = 0; i < n; i++){
    dif = a[i] - dif;

    if(i&1){
      r = min(r, a[i]-dif);
      l = max(l, -dif);
    } else {
      r = min(r, dif);
      l = max(l, dif-a[i]);
    }
  }

  cout << max(r - l + 1, 1LL*0) << "\n";

  return 0;
}

