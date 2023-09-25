#include<cstdio>

void solve() {
  int qp, p, cp = 0, k = 1; scanf("%d %d", &qp, &p);
  //printf("qp:%d p:%d k:%d p&1:%d\n", qp, p, k, p&1);
  while((p&1) != k) {
    int td = (!(qp&1) || !k ? qp/2 : qp/2+1);
    int pd = p/2;
    //printf("qp:%d p:%d cp:%d k:%d td:%d pd:%d\n", qp, p, cp, k, td, pd);
    k = (qp&1) != k;
    p -= pd;
    qp -= td;
    cp += td;
  }
  if(k) cp += p/2+1;
  else cp += p/2;
  printf("%d\n", cp);
}

int main() {
  int qt; scanf("%d", &qt);
  while(qt--) solve();
  return 0;
}
