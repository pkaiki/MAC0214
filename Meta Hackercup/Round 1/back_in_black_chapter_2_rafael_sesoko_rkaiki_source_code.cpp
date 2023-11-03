#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
  int n; cin >> n;
  string s; cin >> s;

  vector<int> arr(s.size(), 0);
  int numbers_to_change = 0;

  for(int i=0; i<s.size(); i++){
    if(s[i] == '1'){
      numbers_to_change++;
      arr[i] = 1;
      for(int j=0; i+j < s.size(); j += i+1){
        if(s[i+j] == '1') s[i+j] = '0';
        else s[i+j] = '1';
      }
    }
  }

  int sum = 0;
  int q; cin >> q;
  for(int i=0; i<q; i++){
    int b; cin >> b;
    b--;

    if(b >= s.size()) continue;

    if(arr[b] == 0){
      arr[b] = 1;
      numbers_to_change++;
      sum += numbers_to_change;
    }

    else{
      arr[b] = 0;
      numbers_to_change--;
      sum += numbers_to_change;
    }
  }

  cout << sum << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  for(int i=1; i<=t; i++){
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
