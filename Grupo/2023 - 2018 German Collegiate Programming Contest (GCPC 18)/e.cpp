#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 10000000

void crivo(vector<int>& ds, vector<int>& ps, int l) {
  ds[1] = 1;
  for(int i=2; i <= l; i++) {
    if(ds[i] == 0) ds[i] = i, ps.push_back(i);
    for(int j : ps) {
      if(j > ds[i] or i*j > l) break;
      ds[i*j] = j;
    }
  }
}

int readd(int q = 5) {
  char c = getchar();
  int r = 0;
  bool p = false;
  //printf("char (%c)\n", c); //DD
  while(c != '\n' && c != ' ') { 
    if(c == '.') p = true;
    else if(q > 0) {
      r *= 10; 
      r += c-'0';
      if(p) q--;
    }
    c = getchar();
    //printf("char (%c)\n", c); //DD
  }
  while(q>0) {
    r *= 10;
    q--;
  }
  return r;
}

void solve(vector<int>& ds) {
  int a = readd(), b = readd(); 
  // printf("solving for a:%d b:%d\n", a, b); //DD
  int da = 0, db = 0;
  vector<int> das, dbs;
  if(a == b) {
    puts("2 2");
    return;
  }
  das.push_back(1);
  dbs.push_back(1);
  while(a != 1) {
    das.push_back(ds[a]);
    a /= ds[a];
  }
  while(b != 1) {
    dbs.push_back(ds[b]);
    b /= ds[b];
  }
  sort(das.begin(), das.end()); 
  sort(dbs.begin(), dbs.end()); 
  while(das.back() != 1 || dbs.back() != 1) {
    //printf("%d(%d) %d(%d)\n", a, ds[a], b, ds[b]); //DD
    if(das.back() > dbs.back()) {
      if(da != 0) {
        puts("impossible");
        return;
      }
      da = das.back();
      das.pop_back();
    }
    else if(dbs.back() > das.back()) {
      if(db != 0) {
        puts("impossible");
        return;
      }
      db = dbs.back();
      dbs.pop_back();
    }
    else {
      das.pop_back();
      dbs.pop_back();
    }
  }
  if(da == 0 || db == 0) 
    puts("impossible");
  else 
    printf("%d %d\n", da, db);
}

int main() {
  int qp; scanf("%d\n", &qp);
  vector<int> ds(MAX+1, 0), ps;
  ps.reserve(MAX);
  crivo(ds, ps, MAX);
  while(qp--) solve(ds);
}
