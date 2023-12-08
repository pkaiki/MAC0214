#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const long double MAXM = 1e16+1;

ll limit[54];
ll memo[10001][54];

ll fastxp(ll base, ll e){
  ll ans = 1;

  while(e){
    if(e&1) ans *= base;
    base *= base;
    e /= 2;
  }

  return ans;
}

void precalc(){
  for(int i = 0; i < 10001; i++)
    for(int j = 0; j < 54; j++)
      memo[i][j] = 1;

  limit[2] = 1000000;
  limit[3] = 50000;

  for(int i = 4; i <= 53; i++){
    limit[i] = (ll)pow(MAXM, (long double)1/i); // codar fastxp e usar pow no mesmo código não é todo dia
    
    for(int j = 2; j <= limit[i]; j++)
      memo[j][i] = fastxp(j, i) + memo[j-1][i];
  }
}

ll eval(ll mid, ll n){
  if(n == 2) return (mid*(mid + 1)*(2*mid + 1))/6;
  if(n == 3) return (mid*mid*(mid+1)*(mid+1))/4;
  return memo[mid][n];
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  precalc();

  ll m; cin >> m;

  for(ll n = 3; n <= 54; n++){
    ll l = 1, r = limit[n-1], mid, aux;

    while(l <= r){
      mid = (l+r)/2;

      aux = eval(mid, n-1);

      if(aux == m){
        cout << n << " " << mid << "\n";
        return 0;
      }

      if(aux < m)
        l = mid+1;
      else
        r = mid-1;
    }
  }

  cout << "impossible\n";

  return 0;
}

