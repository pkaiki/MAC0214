#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
  int n; cin >> n;
  vector<int> h(n);
  vector<int> v(n);
  for(int i=0; i<n; i++) cin >> h[i];
  for(int i=0; i<n; i++) cin >> v[i];

  if(h[0] > v[0]){
    cout << 0 << '\n';
    return;
  }

  int training = max(v[0]-h[0], (int)0);

  bool hero_kicks_win = true;
  for(int i=1; i<n; i++){
    if(v[i] > h[i] + training){
      hero_kicks_win = false;
      break;
    }
    if(h[i] + training > v[i]){
      hero_kicks_win = true;
      break;
    }
  }
  
  cout <<  training + (1 - hero_kicks_win) << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  solve();
  return 0;
}
