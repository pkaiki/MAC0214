#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 8*60+1

int main() {
  int qa, o, mp = 0; scanf("%d %d", &qa, &o); 
  vector<pair<int,int>> as;
  vector<int> cs(MAX, 0); 
  vector<bool> os(MAX, false); 
  for(int i=0; i<qa; i++) {
    int s, d; scanf("%d %d", &s, &d);
    as.push_back({s, d});
  }
  sort(as.begin(), as.end());
  for(pair<int, int>& sd : as) { 
    int s = sd.first, d = sd.second;
    for(int p=s; p<=s+d; p++) {
      if(p < MAX) 
        os[p] = true;
      if((p%o) < MAX)
        cs[p%o]++;
    }
  }
  for(int p=o; p<MAX; p++) {
    cs[p] = cs[p-o];
    if(os[p-o])
      cs[p]--;
  }
  for(int p=0; p<MAX; p++) {
    if(cs[p] < cs[mp])
      mp = p;
  }
  printf("%d %d\n", mp, cs[mp]);
}
