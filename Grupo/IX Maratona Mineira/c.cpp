#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5+1000;
 
int n;
vector<int> k;
 
int memo[MAXN];
 
int dp(int i){
  if(i >= n) return 0;
  if(memo[i] != -1) return memo[i];
  int sum1 = dp(i+1);
  int sum2 = k[i] + dp(i+2);
  return memo[i] = max(sum1, sum2);
}
 
 
 
signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  memset(memo, -1, sizeof(memo));
  cin >> n;
  k.resize(n);
  for(int i=0; i<n; i++) cin >> k[i];
 
  cout << dp(0) << '\n';
 
  return 0;
}
