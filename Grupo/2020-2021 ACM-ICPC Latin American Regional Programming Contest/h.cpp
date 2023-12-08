#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int INF = 1e4+1e3;

struct dinitz{
  const bool scaling = false;
  int lim;
  struct edge{
    int to, cap, rev, flow;
    bool res;
    edge(int to_, int cap_, int rev_, bool res_)
      : to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
  };

  vector<vector<edge>> g;
  vector<int> lev, beg;
  ll F;
  dinitz(int n) : g(n), F(0) {}

  void add(int a, int b, int c) {
    g[a].emplace_back(b, c, g[b].size(), false);
    g[b].emplace_back(a, 0, g[a].size()-1, true);
  }
  bool bfs(int s, int t){
    lev = vector<int>(g.size(), -1); lev[s] = 0;
    beg = vector<int>(g.size(), 0);
    queue<int> q; q.push(s);
    while(q.size()){
      int u = q.front(); q.pop();
      for(auto& i : g[u]){
        if(lev[i.to] != -1 or (i.flow == i.cap)) continue;
        if(scaling and i.cap - i.flow < lim) continue;
        lev[i.to] = lev[u] + 1;
        q.push(i.to);
      }
    }
    return lev[t] != -1;
  }
  int dfs(int v, int s, int f = INF){
    if(!f or v == s) return f;
    for(int& i = beg[v]; i < g[v].size(); i++){
      auto& e = g[v][i];
      if(lev[e.to] != lev[v] + 1) continue;
      int foi = dfs(e.to, s, min(f, e.cap - e.flow));
      if(!foi) continue;
      e.flow += foi, g[e.to][e.rev].flow -= foi;
      return foi;
    }
    return 0;
  }
  ll max_flow(int s, int t){
    for(lim = scaling ? (1<<30)  : 1; lim; lim /= 2)
      while(bfs(s, t)) while(int ff = dfs(s,t)) F += ff;
    return F;
  }
};

void solve(){
  int n; cin >> n;
  dinitz D(110);
  int T = 0;
  int S = 101;
  for(int i=0; i<n; i++){
    int ini;
    if(i == 0) ini = S;
    else ini = i;

    string s; cin >> s;
    if(s == "*"){
      int dst; cin >> dst;
      dst--;
      D.add(ini, dst, INF);
    }
    else{
      int k = stoi(s);
      for(int j=0; j<k; j++){
        int dst; cin >> dst;
        dst--;
        D.add(ini, dst, 1);
      }
    }
  }

  int res = D.max_flow(S, T);

  if(res == INF){
    cout << "*\n";
    return;
  }
  else{
    cout << res + 1 << '\n';
    return;
  }
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  solve();
  return 0;
}
