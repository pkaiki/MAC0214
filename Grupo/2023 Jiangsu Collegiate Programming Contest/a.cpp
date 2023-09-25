#include<cstdio>
#include<vector>

using namespace std;

int main() {
  int qc, qs; scanf("%d %d\n", &qc, &qs);
  int bc = 0, d = 16;
  qc /= 2;
  vector<char> cs(qc), scs(qs);
  for(int i=0; i<qc; i++) getchar(); 
  for(int i=0; i<qc; i++) cs[qc-i-1] = getchar() - 'a'; 
  for(int i=0; i<qs;) {
    for(int j=0; i<qs && j<qc; j++, i++) {
      scs[qs-i-1] = 'a' + (cs[j] + d) % 26; 
      // printf("d:%d\n", d);
    }
    // printf("delta %d %d\n", i/qc, __builtin_ctz(i/qc));
    d = (d + __builtin_ctz(i/qc) + 25) % 26;
  }
  for(int i=0; i<qs; i++) putchar(scs[i]);
  putchar('\n');
  return 0;
}
