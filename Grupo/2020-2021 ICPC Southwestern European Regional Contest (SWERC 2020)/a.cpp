#include <bits/stdc++.h>
#define int long long
using namespace std;

unordered_map<string, int> mp;
unordered_map<string, bool> vis;

void solve(){
  int n, k; cin >> n >> k;
  string b;
  getline(cin, b);
  vector<string> v;
  for(int i=0; i<3*n; i++){
    string s; 
    getline(cin, s);
    mp[s]++;
    vis[s] = 0;
    v.push_back(s);
  }

  vector<tuple<int, int, string>> vv;

  for(int i=v.size()-1; i>=0; i--){
    string s = v[i];
    if(vis[s] == 0){
      vis[s] = 1;
      vv.push_back({mp[s], i, s});
    }
  }
  sort(vv.begin(), vv.end());

  int sz = vv.size();
  //cout << sz << ' ' << sz-1-k+1 << '\n';
  for(int i=sz-1; i>=sz-1-k+1 && i>=0; i--){
    cout << get<2>(vv[i]) << '\n';
  }
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  solve();
  return 0;
}
