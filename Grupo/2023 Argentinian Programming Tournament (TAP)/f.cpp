#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<double> d[2];

double dist2(ll x, ll y, ll tx, ll ty){
  return (x - tx)*(x - tx) + (y - ty)*(y - ty);
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, w, l, tx, ty;
  cin >> n >> w >> l >> tx >> ty;

  d[0].reserve(n);
  d[1].reserve(n);

  for(int k = 0; k < 2; k++){
    for(int i = 0; i < n; i++){
      ll x, y; cin >> x >> y;
      d[k].push_back(dist2(x, y, tx, ty));
    }
  }

  sort(d[0].begin(), d[0].end());
  sort(d[1].begin(), d[1].end());

  if(*d[0].begin() < *d[1].begin())
    cout << "A " << lower_bound(d[0].begin(), d[0].end(), *d[1].begin()) - d[0].begin() << "\n";
  else
    cout << "R " << lower_bound(d[1].begin(), d[1].end(), *d[0].begin()) - d[1].begin() << "\n";

  return 0;
}
 
