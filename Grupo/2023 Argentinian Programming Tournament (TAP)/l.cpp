#include<cstdio>

int main() {
  int a=0, p=0, x, y;
  scanf("%d %d", &x, &y);
  a += x;
  p += y;
  scanf("%d %d", &x, &y);
  a += x;
  p += y;
  if(a == p) puts("D");
  else if(p > a) puts("P");
  else puts("A");
  return 0;
}
