#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
vector<ll> qtd, proposals;

bool check(ll m){
  ll acc = 0;

  for(int i = 0; i < n; i++){
    acc = (acc + proposals[i]) - m*qtd[i];

    if(acc < 0) return false;
  }

  return true;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll l = 0, r = 0, m = 0, best = 0;

  cin >> n;

  qtd.resize(n);
  for(ll &i : qtd) cin >> i;

  proposals.resize(n);
  for(ll &i : proposals){
    cin >> i;
    r = max(i, r);
  }

  while(l <= r){
    m = (l+r)/2;

    if(check(m)){
      best = m;
      l = m+1;
    } else
      r = m-1;
  }

  cout << best << "\n";

  return 0;
}
 
