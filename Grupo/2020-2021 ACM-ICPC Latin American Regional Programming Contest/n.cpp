#include<cstdio>

int readm() {
  int m = 0;
  char c;
  while(getchar() != '$');
  while((c = getchar()) != '.')
    m = m*10 + (c - '0');
  c = getchar();
  m = m*10 + (c - '0');
  c = getchar();
  m = m*10 + (c - '0');
  return m;
}

int main() {
  int qd; scanf("%d", &qd);
  int cl = 0, m = readm();
  for(int i=0; i<qd; i++) {
    m += readm();
    if((m % 100) != 0)
      cl++;
  }
  printf("%d\n", cl);
  return 0;
}
