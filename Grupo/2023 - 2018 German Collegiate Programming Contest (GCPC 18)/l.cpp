#include<cstdio>
#include<vector>

using namespace std;

typedef struct cell {
  int p; bool c;
} cell;

int main() {
  int h, w; scanf("%d %d", &h, &w);
  vector<vector<cell>> cs(h+2, vector<cell>(w+2));
  for(int i=0; i<=h+1; i++) { 
    for(int j=0; j<=w+1; j++) { 
      int p; scanf("%d", &p); 
      cs[i][j] = {p, false};
    }
  }
  for(int i=1; i<=h; i++) { 
    for(int j=1; j<=w; j++) { 
      if(cs[i-1][j-1].p > 0) {
        //printf("coloring %d %d\n", i, j); //DD 
        cs[i][j].c = true;
        for(int k=-1; k<=1; k++)
          for(int l=-1; l<=1; l++) {
            cs[i+k][j+l].p--;
            //printf("reduced %d %d to %d\n", i+k, j+l, cs[i+k][j+l].p); //DD
          }
      }
    }
  }
  for(int i=0; i<=h+1; i++) { 
    for(int j=0; j<=w+1; j++) { 
      if(cs[i][j].p != 0) {
        //printf("%d %d = %d\n", i, j, cs[i][j].p); //DD
        puts("impossible");
        return 0;
      }
    }
  }
  for(int i=1; i<=h; i++) { 
    for(int j=1; j<=w; j++)
      putchar(cs[i][j].c ? 'X' : '.');
    putchar('\n');
  }
  return 0;
}
