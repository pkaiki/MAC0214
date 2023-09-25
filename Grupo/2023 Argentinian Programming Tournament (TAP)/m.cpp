#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int n, t;
vector<ld> prioritized, nprioritized;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> t;

  prioritized.reserve(n); nprioritized.reserve(n);

  for(int i = 0; i < n; i++){
    char c; int x;
    cin >> c >> x;

    if(c == 'P') prioritized.push_back(x);
    else nprioritized.push_back(x);
  }

  sort(prioritized.begin(), prioritized.end());
  sort(nprioritized.begin(), nprioritized.end());

  int i = 0, j = 0;
  ld ans = 0;
  
  ld speed[2]; // {speed prioritized, non-prioritized}
  speed[1] = (ld) t/4;
  speed[0] = t - speed[1];

  while(i < prioritized.size() && j < nprioritized.size()){
    ld time[2] = {(prioritized[i] * (prioritized.size() - i))/speed[0],
                  (nprioritized[j] * (nprioritized.size() - j))/speed[1]};

    if(time[0] < time[1]){ // próximo à acabar é prioritário
      ans += time[0];
      
      for(int ii = i+1; ii < prioritized.size(); ii++)
        prioritized[ii] -= prioritized[i];

      for(int jj = j; jj < nprioritized.size(); jj++)
        nprioritized[jj] -= time[0]*(speed[1]/(nprioritized.size() - j));

      i++;
    } else { // próximo a acabar é não prioritário
      ans += time[1];

      for(int ii = i; ii < prioritized.size(); ii++)
        prioritized[ii] -= time[1]*(speed[0]/(prioritized.size() - i));

      for(int jj = j+1; jj < nprioritized.size(); jj++)
        nprioritized[jj] -= nprioritized[j];

      j++;
    }
  }

  // contabilizar restinho
  while(i < prioritized.size()){
    ans += (prioritized[i] * (prioritized.size() - i))/(ld) t;

    for(int ii = i+1; ii < prioritized.size(); ii++)
      prioritized[ii] -= prioritized[i];

    i++;
  }

  while(j < nprioritized.size()){
    ans += (nprioritized[j] * (nprioritized.size() - j))/(ld) t;

    for(int jj = j+1; jj < nprioritized.size(); jj++)
      nprioritized[jj] -= nprioritized[j];

    j++;
  }

  cout << fixed << setprecision(10) << ans << "\n";

  return 0;
}
 
