#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
  vector<char> cs, r;
  { 
    char c;
    while((c = getchar()) != '\n') cs.push_back(c);
  }
  int qc = cs.size(), qt; scanf("%d", &qt);
  vector<vector<int>> ts(qt);
  r.resize(qc);
  {
    int k = 0;
    while(k < qc) {
      for(int i=0; i<qt && k < qc; i++, k++)
        ts[i].push_back(k); 
      for(int i=qt-2; i>0 && k < qc; i--, k++)
        ts[i].push_back(k); 
    }
  }
  {
    int k = 0;
    for(vector<int>& t : ts) {
      for(int p : t) {
        r[p] = cs[k++]; 
        //printf("%d ", p); //DD
      }
      //putchar('\n'); //DD
    }
  }
  for(char c : r)
    putchar(c);
  putchar('\n');
  return 0;
}
