#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
const int MAXN = 1e6+10;

ld memo[MAXN];

int a, b;
ld p, q; 

ld dp(int x){
  if(x < b) return 0;
  ld& dpm = memo[x];

  if(dpm != 0) return dpm;

  if(b == 1){
    dpm = max( dp(x-b) + 1/(1-q), dp(x-b) + p + 1 );
    return dpm;
  }

  dpm = max(dp(x-b)*(1-q) + dp(x-b+1)*q, dp(x-b) + p) + 1;
  return dpm;
}

void solve(){
  cin >> a >> b >> p >> q;
  p /= 100;
  q /= 100;
  memset(memo, 0, sizeof(memo));
  cout << fixed << setprecision(10);
  cout << dp(a) << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
 
