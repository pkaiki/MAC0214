#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXFIB = 50;
const int oo = 1e17;

int fibo[MAXFIB];

int fib(int x){
  if(x == 0 || x == 1) return 1;
  if(fibo[x] != 0) return fibo[x];
  return fibo[x] = fib(x-1) + fib(x-2);
}

void solve(){
  int n; cin >> n;
  vector<int> m(n);
  multiset<int> st;
  for(int i=0; i<n; i++){
    cin >> m[i];
    st.insert(m[i]);
  }

  auto search = [&m](int A, int B){
    int idxA = -1, idxB = -1;
    for(int i=0; i<m.size(); i++){
      if(m[i] == A && idxA == -1) idxA = i;
      else if(m[i] == B && idxB == -1) idxB = i;
    }
    cout << idxA+1 << ' ' << idxB+1 << '\n';
  };
  
  for(auto A : m){
    auto it = st.find(A);
    st.erase(it);
    if(A == 1){
      auto itt = st.find(1);
      if(itt != st.end()){
        search(1, 1);
        return;
      }
    }

    int maxx = oo;
    int minn = A;

    for(int i=1; i<34; i++){
      if(i%2 == 0){
        if((fib(i)*A - 1)%fib(i-1) == 0){
          auto itr = st.find((fib(i)*A - 1)/fib(i-1));
          if(itr != st.end()){
            int B = *itr;
            if(minn < B && B < maxx && B <= (fib(i+1)*A)/fib(i) ){
              search(A, B);
              return;
            }
          }
        }
        minn = (fib(i+1)*A)/fib(i);
      }
      else{
        if((fib(i)*A + 1)%fib(i-1) == 0){
          auto itr = st.find((fib(i)*A + 1)/fib(i-1));
          if(itr != st.end()){
            int B = *itr;
            if(minn < B && B < maxx && B >= (fib(i+1)*A + fib(i) - 1)/fib(i) ){
              search(A, B);
              return;
            }
          }
        }
        maxx = (fib(i+1)*A + fib(i) - 1)/fib(i);
      }
    }

    st.insert(A);
  }
  cout << "impossible\n";
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  solve();
  return 0;
}
