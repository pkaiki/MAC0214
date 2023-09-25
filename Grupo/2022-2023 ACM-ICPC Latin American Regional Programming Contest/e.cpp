#include <bits/stdc++.h>
using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, e; cin >> n >> k >> e;

  vector<int> gap = {e, k, n-(e+k)};

  int cont = 0;
  for(int i = 0; i < 3; i++)
    if(gap[i] >= 5) cont++;

  if(cont >= 2){ // se pelo menos dois buracos são >= 5, deu bão
    cout << "0\n";
    return 0;
  }

  if(cont == 1 && gap[1] < 5){
    int aux = min(gap[0], gap[2]);

    vector<int> tiles; tiles.reserve(3);
    for(int i = 1; i <= 4; i++)
      if(i != gap[1])
        tiles.push_back(i);

    int best = aux;

    do {
      int to_fill = aux;

      for(int i = 0; i < tiles.size(); i++){
        if(to_fill - tiles[i] >= 0) to_fill -= tiles[i];
        else break;
      }

      best = min(best, to_fill);
    } while(next_permutation(tiles.begin(), tiles.end()));

    cout << best << "\n";

    return 0;
  }

  // caso três menores ou o já coberto for o maior
  vector<int> tiles; tiles.reserve(3);
  for(int i = 1; i <= 4; i++)
    if(i != gap[1])
      tiles.push_back(i);

  int best = gap[0] + gap[2];
  do {
    vector<int> to_fill = {gap[0], gap[2]};
    int k = 0;

    // preenchendo na ordem certa
    while(to_fill[0] > 0 && k < tiles.size()){
      if(to_fill[0] - tiles[k] >= 0) to_fill[0] -= tiles[k++];
      else break;
    }

    while(to_fill[1] > 0 && k < tiles.size()){
      if(to_fill[1] - tiles[k] >= 0) to_fill[1] -= tiles[k++];
      else break;
    }

    best = min(best, to_fill[0] + to_fill[1]);

    to_fill = {gap[2], gap[0]};
    k = 0;

    // preenchendo ao contrário
    while(to_fill[1] > 0 && k < tiles.size()){
      if(to_fill[1] - tiles[k] >= 0) to_fill[1] -= tiles[k++];
      else break;
    }

    while(to_fill[0] > 0 && k < tiles.size()){
      if(to_fill[0] - tiles[k] >= 0) to_fill[0] -= tiles[k++];
      else break;
    }

    best = min(best, to_fill[0] + to_fill[1]);

  } while(next_permutation(tiles.begin(), tiles.end()));

  cout << best << "\n";

  return 0;
}
 
