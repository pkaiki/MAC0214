#include <bits/stdc++.h>
#define int long long
using namespace std;

void factor(int p, vector<int>& prime_factors){
  for(int i=2; i <= 41; i++){
    if(p%i == 0){
      while(p%i == 0){
        prime_factors.push_back(i);
        p/=i;
      }
    }
  }
  if(prime_factors.empty()) prime_factors.push_back(p);
}

void solve(){
  int p; cin >> p;
  vector<int> prime_factors;
  factor(p, prime_factors);
  int prod = 1;
  int sum = 0;
  for(auto x : prime_factors){
    prod *= x;
    sum += x;
  }

  if(prod != p || sum > 41){
    cout << -1 << '\n';
    return;
  }

  for(int i=0; i<41-sum; i++){
    prime_factors.push_back(1);
  }

  cout << prime_factors.size() << ' ';
  for(auto x : prime_factors) cout << x << ' ';
  cout << '\n';
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
