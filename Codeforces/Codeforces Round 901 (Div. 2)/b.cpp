#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
  int n, m, k; cin >> n >> m >> k;
  vector<int> a(n);
  vector<int> b(m);
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<m; i++) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  if(a[0] < b[m-1]) swap(a[0], b[m-1]);

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  if(k%2 == 0) swap(a[n-1], b[0]);

  int sum = 0;
  for(int i=0; i<n; i++) sum += a[i];
  cout << sum << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
