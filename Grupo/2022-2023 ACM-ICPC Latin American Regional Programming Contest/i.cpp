#include<queue>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int ds[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int ofs(vector<vector<int>>& os, vector<vector<int>>& vs, int v, int y, int x) {
  priority_queue<pair<int,pair<int,int>>> po;
  int co = os[y][x], gc = 0;
  po.push({-os[y][x], {y, x}});
  while(!po.empty()) {
    pair<int,pair<int,int>> ao = po.top(); po.pop();
    int ay = ao.second.first, ax = ao.second.second;
    co = -ao.first;
    gc++;
    for(int i=0; i<4; i++) {
      int by = ay+ds[i][0], bx = ax+ds[i][1];
      if(
        by >= 0 && by < vs.size() && 
        bx >= 0 && bx < vs[0].size() && 
        vs[by][bx] != v && os[by][bx] > co
      ) {
        vs[by][bx] = v;
        po.push({-os[by][bx], {by, bx}});
      }
    }
  }
  return gc;
}

int main() {
  int qr, qc, v=0, mgc = 0; scanf("%d %d", &qr, &qc);
  vector<vector<int>> os(qr, vector<int>(qc)), vs(qr, vector<int>(qc, 0));
  for(vector<int>& r : os) for(int& o : r) scanf("%d", &o); 
  for(int y=0; y<qr; y++) for(int x=0; x<qc; x++)
    mgc = max(mgc, ofs(os, vs, ++v, y, x));
  printf("%d\n", mgc);
  return 0;
}
