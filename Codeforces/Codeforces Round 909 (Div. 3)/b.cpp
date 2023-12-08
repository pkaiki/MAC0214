#include <bits/stdc++.h>
#define int long long
using namespace std;

const int oo = 1e17;

void solve(){
  int n; cin >> n;
  vector<int> a(n+1, 0);
  vector<int> acc(n+1, 0);
  for(int i=1; i<=n; i++){
    cin >> a[i];
    acc[i] = acc[i-1] + a[i];
  }

  int max_dif = 0;

  for(int k=1; k<=n; k++){
    int minn = oo;
    int maxx = 0;
    if(n%k == 0){
      for(int i=0; i<n/k; i++){
        minn = min(minn, acc[k*(i+1)] - acc[k*i]);
        maxx = max(maxx, acc[k*(i+1)] - acc[k*i]);
      }
    }
    
    max_dif = max(max_dif, maxx - minn);
  }

  cout << max_dif << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
