#include<cstdio>
#include<vector>
#include<set>

using namespace std;

int main() {
  int qi, qs, dl, dh, sc=0; scanf("%d %d %d %d", &qi, &qs, &dl, &dh);
  vector<vector<pair<int,int>>> bss(qi);
  vector<int> ds(qi, -1);
  vector<bool> vs(qi, false);
  set<pair<int,int>> queue;
  for(int i=0; i<qs; i++) {
    int a, b, d; scanf("%d %d %d", &a, &b, &d);
    bss[a].push_back({d,b});
    bss[b].push_back({d,a});
  }
  ds[0] = 0;
  queue.insert({ds[0], 0});
  while(!queue.empty()) {
    pair<int,int> da = *queue.begin(); queue.erase(da);
    int d = da.first, a = da.second;
    if(vs[a]) continue;
    vs[a] = true;
    for(pair<int,int> db : bss[a]) {
      int b = db.second, nd = d + db.first;
      if(!vs[b]) sc++;
      // if nd*2 >= dh we dont want this intersection
      if(nd*2 < dh && (ds[b] == -1 || nd < ds[b])) {
        //printf("going from %d to %d nd:%d\n", a, b, nd); //dd
        ds[b] = nd;
        queue.insert({nd, b});
      }
    }
  }
  printf("%d\n", sc);
  return 0;
}
