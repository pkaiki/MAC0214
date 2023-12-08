#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10;

vector<pair<int,int>> arr;
set<pair<int, int>> l, r;

int sum[N];
int op[N];

void update_op(int a, int b){
  if(a > b) return;
  op[a]++;
  op[b+1]--;
}

void update_sum(int n){
  int acc = 0;
  for(int i=0; i<n; i++){
    acc += op[i];
    sum[i] = acc;
  }
}
 
void solve(){
  int n; cin >> n;
  arr.resize(n);
  for(int i=0; i<n; i++){
    cin >> arr[i].first;
    arr[i].second = i;
  }

  sort(arr.begin(), arr.end(), greater<>());

  for(auto [num, i] : arr){
    auto pl = l.lower_bound(make_pair(-i, 0));
    auto pr = r.lower_bound(make_pair(i, 0));

    if(pl == l.end()){
      update_op(0, i-1);
    }

    else{
      int left = -(pl->first);
      update_op((left+i)/2+1, i-1);
    }

    if(pr == r.end()){
      update_op(i+1, n-1);
    }

    else{
      int right = pr->first;
      update_op(i+1, (right+i+1)/2-1);
    }

    l.insert(make_pair(-i, num));
    r.insert(make_pair(i, num));
  }

  update_sum(n);

  for(int i=0; i<n; i++){
    cout << sum[i] << ' ';
  }
  cout << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  solve();
  return 0;
}
