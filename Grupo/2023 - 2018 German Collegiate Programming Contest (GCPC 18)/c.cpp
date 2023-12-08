#include<cstdio>
#include<vector>

using namespace std;

int main() {
  int qp, qs; scanf("%d %d", &qp, &qs);
  vector<vector<pair<int,int>>> bss(qp);
  vector<int> cps(qp, 0), cs(qp, 0), zps;
  int m = 0;
  for(int i=0; i<qs; i++) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    a--; b--;
    bss[a].push_back({b, c});
    cps[b]++;
    // printf("read %d %d %d\n", a+1, b+1, bss[a].back().second); //DD
  }
  for(int i=0; i<qp; i++) {
    if(cps[i] == 0)
      zps.push_back(i);
  }
  while(!zps.empty()) {
    int a = zps.back(); zps.pop_back();
    // printf("visiting %d c:%d\n", a+1, cs[a]); //DD
    for(pair<int,int>& bc : bss[a]) {
      int b = bc.first;
      int c = bc.second;
      // printf("to %d cb:%d nc:%d\n", b+1, cs[b], cs[a]+c); //DD
      if(cs[a] + c > cs[b]) {
        cs[b] = cs[a]+c;
        if(cs[b] > m)
          m = cs[b];
      }
      cps[b]--;
      if(cps[b] == 0)
        zps.push_back(b);
    }
  }
  printf("%d\n", m);
  /*
  */
  return 0;
}
