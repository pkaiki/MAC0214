#include<cstdio>

int main() {
  int qt; scanf("%d", &qt);
  while(qt--) {
    int qp, qf; scanf("%d %d", &qp, &qf);
    printf("%d\n", qp-qf+1);
  }
  return 0;
}
