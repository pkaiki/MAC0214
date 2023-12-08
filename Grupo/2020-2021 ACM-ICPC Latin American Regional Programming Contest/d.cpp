#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5 + 10;

int freq[MAXN];

void solve(){
  int n; cin >> n;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    freq[x]++;
  }

  if(n == 1){
    cout << "N\n";
    return;
  }

  int num = 0;

  for(int i=0; i<MAXN; i++){
    if(freq[i]%2 == 1) num++;
    freq[i+1] += freq[i]/2;
  }

  if(num <= 2){
    cout << "Y\n";
    return;
  }
  else{
    cout << "N\n";
    return;
  }
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  solve();
  return 0;
}
