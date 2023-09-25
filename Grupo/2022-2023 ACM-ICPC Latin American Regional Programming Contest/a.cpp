#include <bits/stdc++.h>
using namespace std;
#define MAXN 1010

vector<int> g[MAXN];
vector<int> revg[MAXN];
bool reach[MAXN][MAXN];
bool vis[MAXN];
bool vis1[MAXN];
bool vis2[MAXN];

void dfs(int s, int u){
  vis[u] = true;
  reach[s][u] = true;
  for(auto v : g[u]){
    if(vis[v]) continue;
    dfs(s, v);
  }
}

void dfs1(int person, int u){
  vis1[u] = true;
  for(auto v : revg[u]){
    if(vis1[v]) continue;
    if(v == person) continue;
    dfs1(person, v);
  }
}

bool dfs2(int person, int u){
  vis2[u] = true;
  if(vis1[u] && reach[u][person]) return true;
  for(auto v : revg[u]){
    if(vis2[v]) continue;
    if(v == person) continue;
    if(dfs2(person, v)) return true;
  }
  return false;
}

void solve(){
  int n; cin >> n;
  for(int i=0; i<n; i++){
    int x, y; cin >> x >> y;
    x--; y--;
    g[i].push_back(x);
    g[i].push_back(y);
    revg[x].push_back(i);
    revg[y].push_back(i);
  }

  for(int i=0; i<n; i++){
    memset(vis, 0, sizeof(vis));
    dfs(i, i);
  }

  int f1, f2;
  for(int i=0; i<n; i++){
    bool canLose = false;
    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));
    f1 = g[i][0], f2 = g[i][1];
    dfs1(i, f1);
    if(dfs2(i, f2)) canLose = true;

    /*
    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));

    f1 = g[i][1], f2 = g[i][0];
    dfs1(i, f1);
    if(dfs2(i, f2)) canLose = true;
    */

    if(canLose) cout << "Y";
    else cout << "N";
  }
  cout << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
 
