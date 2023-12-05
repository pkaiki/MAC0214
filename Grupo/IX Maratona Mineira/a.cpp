#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e3+100;
 
int colocou[MAXN][MAXN];
int d[MAXN][MAXN];
 
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
 
signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int A = 1;
  int B = 0;
 
  char mapa[MAXN][MAXN];
 
  int N, M, T, ci, cj; cin >> N >> M >> T >> ci >> cj;
  ci--;
  cj--;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> mapa[i][j];
      if(mapa[i][j] == '.') B++;
    }
  }
 
  queue<pair<int, int>> fila;
  fila.push(make_pair(ci, cj));
  colocou[ci][cj] = true;
  while(!fila.empty()){
    auto [x, y] = fila.front();
    fila.pop();
    for(int i=0; i<4; i++){
      int xx = x + dx[i];
      int yy = y + dy[i];
      if(mapa[xx][yy] == '#') continue;
      if(xx < 0 || yy < 0 || xx >= N || yy >= M) continue;
      if(!colocou[xx][yy]){
        fila.push(make_pair(xx, yy));
        colocou[xx][yy] = true;
        d[xx][yy] = d[x][y] + 1;
        if(d[xx][yy] <= T) A++;
      }
    }
  }
 
  int dd = __gcd(A,B);
  A /= dd;
  B /= dd;
 
  cout << A << ' ' << B << '\n';
 
  return 0;
}
