#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define MOD 1000000007
typedef long long ll;

int main() {
  int qk, o, qd; scanf("%d %d", &qk, &o);
  vector<vector<int>> ds(qk, vector<int>(qk));
  vector<int> pds;
  vector<ll> vs(qk, 1), avs(qk+1);
  ll s = 0;
  for(vector<int>& r : ds)
    for(int& d : r)
      scanf("%d", &d);
  scanf("%d", &qd);
  pds.resize(qd-1);
  for(int& pd : pds)
    scanf("%d", &pd);
  /*DDDDD
  for(vector<int>& r : ds) {
    for(int& d : r)
      printf("%3d ", d);
    putchar('\n');
  }
  //DDDDD*/
  for(int p=qd-2; p>=0; p--) {
    s = 0;
    avs[0] = s;
    for(int k=0; k<qk; k++) {
      // printf("%3d ", vs[k]); //DD
      s += vs[k];
      s %= MOD;
      avs[k+1] = s;
    }
    // putchar('\n'); //DD
    for(int k=0; k<qk; k++) {
      int l = lower_bound(ds[k].begin(), ds[k].end(), pds[p]-o)-ds[k].begin();       
      int u = upper_bound(ds[k].begin(), ds[k].end(), pds[p]+o)-ds[k].begin();       
      // printf("pd:%d k:%d [%d,%d)\n", pds[p], k, l, u); //DD
      if(u <= l)
        vs[k] = 0;
      else
        vs[k] = (avs[u]-avs[l]+MOD)%MOD;
    }
  }
  s = 0;
  for(int k=0; k<qk; k++) {
    // printf("%3d ", vs[k]); //DD
    s += vs[k];
    s %= MOD;
  }
  // putchar('\n'); //DD
  printf("%lld\n", s); 
  return 0;
}
