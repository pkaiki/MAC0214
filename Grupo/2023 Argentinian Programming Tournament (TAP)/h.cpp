#include<cstdio>
#include<vector>

using namespace std;

int main() {
  int n, m=0; scanf("%d", &n);
  vector<pair<int,int>> ps(n*n); 
  vector<int> rs(n,0), cs(n,0);
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      int v; scanf("%d", &v);
      ps[v-1] = {i, j}; 
    }
  }
  for(int i=0; i<n*n; i++) {
    int lr = rs[ps[i].first], lc = cs[ps[i].second];
    rs[ps[i].first] = max(lr, lc+1); 
    cs[ps[i].second] = max(lc, lr+1); 
  }
  for(int i=0; i<n; i++)
    m = max(m, max(rs[i], cs[i]));
  printf("%d\n", m);
}
