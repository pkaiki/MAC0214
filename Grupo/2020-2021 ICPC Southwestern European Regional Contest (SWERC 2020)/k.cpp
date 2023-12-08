#include <bits/stdc++.h>
#define int long long
using namespace std;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}

template<int MOD> struct str_hash{
  static int P;
  vector<int> h, p;
  str_hash(string s) : h(s.size()), p(s.size()) {
    p[0] = 1, h[0] = s[0];
    for(int i=1; i<s.size(); i++){
      p[i] = p[i-1] * P % MOD;
      h[i] = (h[i-1] * P + s[i])%MOD;
    }
  }
  int operator()(int l, int r) {
    int hash = h[r] - (l ? h[l-1]*p[r-l+1]%MOD : 0);
    return hash < 0 ? hash + MOD : hash;
  }
};

template<int MOD> int str_hash<MOD>::P = uniform(256, MOD-1);

void solve(){
  const int modulo = 1e9+123;
  string s; cin >> s;
  str_hash<modulo> s_hash(s);

  int l = 0, r = s.size(), best_size = -1;
  int best_i = -1;
  while(l <= r){
    int mid = (l+r)/2;
    map<int, int> appeard;
    for(int i=0; i+mid-1 < s.size(); i++){
      appeard[s_hash(i, i+mid-1)]++;
    }
    for(int i=0; i+mid-1 < s.size(); i++){
      if(appeard[s_hash(i, i+mid-1)] == 1){
        best_i = i;
        best_size = mid;
        r = mid-1;
        break;
      }
    }
    if(best_size != mid) l = mid+1;
  }
  cout << s.substr(best_i, best_size) << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  solve();
  return 0;
}

