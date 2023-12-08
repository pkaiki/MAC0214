#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
  int n, p, h; cin >> n >> p >> h;
  vector<char> move(n);
  vector<bool> isUpper(n, false);

  int two_power[65];
  two_power[0] = 1;
  for(int i=1; i<65; i++) two_power[i] = two_power[i-1] * 2;

  int cur_state = n;
  while(cur_state > 0){
    if(h > two_power[cur_state-1]){
      isUpper[cur_state-1] = true;
      h = two_power[cur_state] - h + 1;
    }
    cur_state--;
  }

  for(int i=0; i<n; i++){
    if(p <= two_power[n-i-1]){
      if(isUpper[i]){
        p = two_power[n-i-1] - p + 1;
        cout << "L";
      }
      else cout << "R";
    }
    else{
      if(isUpper[i]){
        p = two_power[n-i] - p + 1;
        cout << "R";
      }
      else{
        p = p - two_power[n-i-1];
        cout << "L";
      }
    }
  }

  cout << '\n';
}
signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  solve();
  return 0;
}
