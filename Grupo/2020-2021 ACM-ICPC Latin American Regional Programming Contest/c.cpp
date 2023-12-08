#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
  int n; cin >> n;
  vector<int> G(n);
  int mean = 0;
  for(int i=0; i<n; i++){
    cin >> G[i];
    mean += G[i];
  }
  mean /= n;

  vector<int> CW, CCW;
  int acc;

  int sum1 = 0;
  CW = G;
  acc = 0;
  for(int i=0; i<2*n; i++){
    int id = i%n;
    int has = CW[id] + acc;
    if(has <= mean){
      CW[id] = has;
      acc = 0;
    }
    else{
      CW[id] = mean;
      acc = has - mean;
      sum1 += has - mean;
    }
  }

  int sum2 = 0;
  CCW = G;
  acc = 0;
  for(int i=2*n-1 ; i>=0; i--){
    int id = i%n;
    int has = CCW[id] + acc;
    if(has <= mean){
      CCW[id] = has;
      acc = 0;
    }
    else{
      CCW[id] = mean;
      acc = has - mean;
      sum2 += has - mean;
    }
  }

  cout << min(sum1, sum2) << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  solve();
  return 0;
}
