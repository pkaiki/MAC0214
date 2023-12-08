#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 5e3+500;
const int oo = 1e17;

int memo[MAXN];
int n;

int dp(int mex, map<int,int>& freq){
  if(mex == 0) return 0;
  int& dpm = memo[mex];
  if(dpm != -1) return dpm;

  dpm = oo;

  for(int i=0; i < n && i < mex; i++){
    dpm = min(dpm, mex * (freq[i]-1) + i + dp(i, freq));
  }

  return dpm;
}

void solve(){
  memset(memo, -1, sizeof(memo));
  cin >> n;
  vector<int> a(n);
  map<int, int> freq;
  for(int i=0; i<n; i++){
    cin >> a[i];
    freq[a[i]]++;
  }

  for(int i=0; i<=n; i++){
    if(freq[i] == 0){
      cout << dp(i, freq) << '\n';
      return;
    }
  }
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
