#include <bits/stdc++.h>
#define int long long
using namespace std;


int find_root(int a, int b, int c){
	int res = -1, l = 0, r = 1e5+5000;
	while(l <= r){
		int mid = (l+r)/2;
		if(a*mid*mid + b*mid + c > 0) r = mid-1;
		if(a*mid*mid + b*mid + c == 0) return mid;
		if(a*mid*mid + b*mid + c < 0) l = mid+1;
	}
	return res;
}

void solve(){
	int A, S, L, R; cin >> A >> S >> L >> R;

	int sum = 0;

	for(int q=1; q <= R-L+1; q++){
		int lmin = (A-L)/q;
		int rmax = (R-A)/q;
		for(int l=0; l<=lmin; l++){
			int r = find_root(q, (2*A + q), (2*A*l - q*l*l + 2*A - q*l - 2*S));
			//cout << "O valor de q e l eh "<< q << ' ' << l << ' ' << r << endl;
			if(r == -1) continue;
			if(r <= rmax)
        if(l || r) sum++;
		}
	}

  if(A == S) sum++;
	
	cout << sum << '\n';
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}

