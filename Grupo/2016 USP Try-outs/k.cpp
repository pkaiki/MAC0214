#include <bits/stdc++.h>
#define int long long
using namespace std;

bool probability(int n, int x){
  double prob = 1;
  double den = n;
  double num = n;
  for(int i=0; i<x; i++){
    prob *= den/num;
    den--;
  }
  prob = 1-prob;
  return prob > 0.5;
}

void solve(){
  int n; cin >> n;
  int l = 0, r = n+1;
  while(l + 1 < r){
    int mid = (l+r)/2;
    if(probability(n, mid)) r = mid;
    else l = mid;
  }
  cout << r << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
 
