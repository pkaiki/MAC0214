    #include <bits/stdc++.h>
    using namespace std;
     
    const int MAX = 410, INF = 0x3f3f3f3f;
     
    int seg[2*MAX][2*MAX], N;
     
    int query(int x1, int y1, int x2, int y2){
      int ret = -1, y3 = y1 + N, y4 = y2 + N;
     
      for(x1 += N, x2 += N; x1 <= x2; ++x1 /= 2, --x2 /= 2)
        for(y1 = y3, y2 = y4; y1 <= y2; ++y1 /=2, --y2 /= 2){
          ret = max(ret, seg[x1][y1]);
          ret = max(ret, seg[x1][y2]);
          ret = max(ret, seg[x2][y1]);
          ret = max(ret, seg[x2][y2]);
        }
     
      return ret;
    }
     
    void update(int x, int y, int val){
      int y2 = y += N;
     
      for(x += N; x; x /= 2, y = y2){
        if(x >= N) seg[x][y] = val;
        else seg[x][y] = max(seg[2*x][y], seg[2*x+1][y]);
     
        while(y /= 2) seg[x][y] = max(seg[x][2*y], seg[x][2*y+1]);
      }
    }
     
    signed main(){
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
     
      for(int i = 0; i < 2*MAX; i++)
        for(int j = 0; j < 2*MAX; j++)
          seg[i][j] = INF;
     
      int n, m;
      cin >> n >> m;
      N = max(n, m);
     
      int k; cin >> k;
     
      int q; cin >> q;
     
      while(q--){
        int a, b, d; cin >> a >> b >> d;
        a--; b--;
        update(a, b, d);
      }
     
      int ans = INF;
     
      for(int i = 0; i <= n-k; i++)
        for(int j = 0; j <= m-k; j++)
          ans = min(ans, query(i, j, i+k-1, j+k-1));
     
      cout << (ans < INF ? ans : -1) << "\n";
     
      return 0;
    }
     
