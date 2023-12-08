#include <bits/stdc++.h>
#define int long long
using namespace std;

const int oo = 1e17;
const int pos = 1e4;

void solve(){
  int n; cin >> n;
  vector<int> a(n+1, -oo);
  for(int i=1; i<=n; i++) cin >> a[i];

  int maxx = -oo;
  int sum = 0;
  for(int i=1; i<=n; i++){
    if(i == 1 || ((a[i]+pos)%2) != ((a[i-1]+pos)%2)){
      sum += a[i];
      //cout << i << ' ' << a[i] << ' ' << sum << '\n';
      maxx = max(maxx, sum);
    }

    else{
      sum = a[i];
      maxx = max(maxx, sum);
    }

    if(sum <= 0){
      sum = 0;
    }
  }
  cout << maxx << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
