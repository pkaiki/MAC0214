#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
  int a, b, n; cin >> a >> b >> n;
  int sum = 0;
  sum += b-1;
  int c = 1;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    c = min(a, c+x);
    sum += c-1;
    c = 1;
  };
  cout << sum+1 << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
