#include <bits/stdc++.h>
typedef double ld;
using namespace std;

#define x first
#define y second

const ld eps = 1e-5;

ld X, Y;
int N;
vector<ld> raio;
vector<pair<ld,ld>> point;
vector<vector<int>> g;
vector<bool> vis;

int top, esq, dir, bot;

void dfs(int u){
  vis[u] = true;
  for(auto v : g[u]){
    if(vis[v]) continue;
    dfs(v);
  }
}

bool is_possible(ld r){
  g.resize(N+10);
  vis.resize(N+10, 0);
  for(int i=0; i<N; i++){
    for(int j=i+1; j<N; j++){
      ld dist = hypotl( point[i].x - point[j].x, point[i].y - point[j].y );
      if(dist < 2*r){
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }

  for(int i=0; i<N; i++){
    if(Y-point[i].y < r){
      g[i].push_back(top);
      g[top].push_back(i);
    }
    if(X-point[i].x < r){
      g[i].push_back(dir);
      g[dir].push_back(i);
    }
    if(point[i].y < r){
      g[i].push_back(bot);
      g[bot].push_back(i);
    }
    if(point[i].x < r){
      g[i].push_back(esq);
      g[esq].push_back(i);
    }
  }

  dfs(top); 
  dfs(esq);

  g.clear();
  vis.clear();
  if(vis[dir] || vis[bot]) return false;
  return true;
}

void solve(){
  cin >> X >> Y;
  cin >> N;
  point.resize(N);
  top = N+1, esq = N+2, dir = N+3, bot = N+4;

  for(int i=0; i<N; i++){
    ld xi, yi; cin >> xi >> yi;
    point[i].x = xi;
    point[i].y = yi;
  }

  ld l = 0, r = 1e6+500;
  while(abs(l-r) - eps > 0){
    ld mid = (l+r)/2;
    if(is_possible(mid)) l = mid;
    else r = mid;
  }
  cout << fixed << setprecision(10);
  cout << r << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  solve();
  return 0;
}
