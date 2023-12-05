#include<cstdio>
#include<vector>

using namespace std;

typedef long long ll;

int ds[8][2] = {{0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}};

int main() {
  ll r = -1;
  int qy, qx; scanf("%d %d", &qy, &qx);
  vector<vector<ll>> vs(qy, vector<ll>(qx));
  for(vector<ll>& vr : vs) 
    for(ll& v : vr)
      scanf("%lld", &v);
  int y, x; scanf("%d %d", &y, &x);
  y--; x--;
  if(qy == qx && qy == 1) {
    printf("%lld\n", vs[0][0]);
    return 0;
  }
  for(int i=0; i<qy+qx; i++) {
    int md = 0;
    ll qa = 0, mv = -1;
    for(int j=0; j<8; j++) {
      int ny = y + ds[j][0];
      int nx = x + ds[j][1];
      if(ny >= 0 && ny < qy && nx >= 0 && nx < qx) 
        qa++;    
    }
    ll dv = vs[y][x]/qa;
    vs[y][x] %= qa;
    for(int j=0; j<8; j++) {
      int ny = y + ds[j][0];
      int nx = x + ds[j][1];
      if(ny >= 0 && ny < qy && nx >= 0 && nx < qx) {
        vs[ny][nx] += dv;
        if(vs[ny][nx] > mv) {
          md = j;
          mv = vs[ny][nx];
        }
      }
    }
    /*DDD
    printf("after step %d\n", i+1);
    for(int cy=0; cy<qy; cy++) {
      for(int cx=0; cx<qx; cx++)
        printf("%3lld%c", vs[cy][cx], (y == cy && x == cx ? '<' : ' '));
      putchar('\n');
    }
    //DDD */
    y += ds[md][0];
    x += ds[md][1];
  }
  for(vector<ll>& vr : vs)
    for(ll v : vr)
      if(v > r)
        r = v;
  printf("%lld\n", r);
}
