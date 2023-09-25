#include <bits/stdc++.h>
using namespace std;

const int MAXS = 50+5;
  
int memo[MAXS][MAXS];

int dp(int i, int j, string& s1, string& s2){
  int n1 = s1.size(), n2 = s2.size();
  int& dpm = memo[i][j];
  if(dpm != -1) return dpm;
  if(i == n1 || j == n2) return 0;
  if(s1[i] == s2[j]) dpm = dp(i+1, j+1, s1, s2)+1;
  if(s1[i] != s2[j]) dpm = 0;
  return dpm;
}

void solve(){
  int n; cin >> n;
  string s[n];
  int res = 0;
  for(int i=0; i<n; i++) cin >> s[i];
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      memset(memo, -1, sizeof(memo));
      for(int i1=0; i1<s[i].size(); i1++){
        for(int j1=0; j1<s[j].size(); j1++){
          res = max(res, dp(i1, j1, s[i], s[j]));
        }
      }
    }
  }
  cout << res << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
