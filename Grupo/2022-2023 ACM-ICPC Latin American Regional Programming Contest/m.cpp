#include<vector>
#include<bitset>
#include<cstdio>
#include<cassert>

using namespace std;

int ds[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void getrs(
  vector<bitset<100>>& hs, 
  bitset<100>& ps, 
  vector<vector<bool>>& rs
) {
  int qr = rs.size(), qc = rs[0].size();
  for(int x=0; x<qc; x++) {
    for(int y=0; y<qr; y++)
      rs[y][x] = (ps&hs[y]).none();
    bool l = ps.test(qc-1);
    ps <<= 1;
    ps.set(0, l);
  }
}

bool dfs(vector<vector<bool>>& rs) {
  int qr = rs.size(), qc = rs[0].size();
  vector<pair<int,int>> as;
  for(int i=0; i<rs[0].size(); i++) if(rs[0][i]) {
    as.push_back({0,i}); 
    while(!as.empty()) {
      pair<int,int> a = as.back(); as.pop_back();
      int ay = a.first, ax = a.second;
      if(ay == rs.size()-1) 
        return true;
      rs[ay][ax] = false;
      for(int j=0; j<4; j++) {
        int by = ay+ds[j][0], bx = (ax+qc+ds[j][1])%qc;
        if(by >= 0 && by < qr && rs[by][bx])
          as.push_back({by, bx});
      }
    }
  }
  return false;
}

int main() {
  int qr, qc; scanf("%d %d\n", &qr, &qc);
  vector<bitset<100>> hs(qr);
  bitset<100> ps, rps;
  vector<vector<bool>> rs(qr, vector<bool>(qc));
  //printf("qr:%d qc:%d rsr:%ld rsc:%ld\n", qr, qc, rs.size(), rs[0].size()); //DD
  for(int x=0; x<qc; x++) {
    bool v = (getchar() == '1');
    ps.set(x, v);
    rps.set(qc-x-1, v);
  }
  getchar();
  for(int y=0; y<qr; y++) {
    for(int x=0; x<qc; x++)
      hs[y].set(x, (getchar() == '1'));
    getchar();
  }
  getrs(hs, ps, rs);
  /*DDD
  printf("qr:%d qc:%d rsr:%ld rsc:%ld\n", qr, qc, rs.size(), rs[0].size());
  for(vector<bool>& r : rs) {
    for(bool v : r)
      putchar(v ? '#' : '.');
    putchar('\n');
  }
  //DDD*/
  if(dfs(rs)) {
    puts("Y");
    return 0;
  }
  getrs(hs, rps, rs);
  if(dfs(rs)) {
    puts("Y");
    return 0;
  }
  puts("N");
  return 0;
}
