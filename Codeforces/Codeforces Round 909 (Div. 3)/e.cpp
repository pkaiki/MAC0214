#include <bits/stdc++.h>
#define int long long
using namespace std;

const int oo = 1e17;

void solve(){
  int n; cin >> n;
  int minn = oo;
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
    minn = min(minn, a[i]);
  }
  int sum = 0;
  for(int i=0; i<n; i++){
    if(a[i] == minn){
      bool right = true; 
      for(int j=i+1; j<n; j++){
         if(a[j] < a[j-1]) right = false;
      }

      if(right){
        cout << sum << '\n';
        return;
      }
      else{
        cout << -1 << '\n';
        return;
      }
    }
    sum++;
  }
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
