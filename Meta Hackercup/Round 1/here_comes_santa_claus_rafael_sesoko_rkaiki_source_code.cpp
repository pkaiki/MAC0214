#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
  cout << fixed << setprecision(8);
  int n; cin >> n;
  vector<long double> x(n);
  for(int i=0; i<n; i++) cin >> x[i];
  sort(x.begin(), x.end());

  if(n == 4 || n > 5){
    long double ini = (x[0] + x[1])/2;
    long double end = (x[n-1] + x[n-2])/2;
    cout << end-ini << '\n';
  }

  else{
    long double ini = (x[0] + x[2])/2;
    long double end = (x[n-1] + x[n-2])/2;
    long double res1 = end-ini;
    ini = (x[0] + x[1])/2;
    end = (x[n-1] + x[n-3])/2;
    long double res2 = end - ini;
    cout << max(res1, res2) << '\n';
  }

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
