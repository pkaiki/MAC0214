#include <bits/stdc++.h>
#define int long long
typedef long double ld;
const ld pi = acos(-1);
 
using namespace std;
 
bool is_less(int x1, int y1, int x2, int y2){
	if(x1 == 0) return true;
	if(y1*x2 < y2*x1) return true;
	return false;
}
 
ld find_max(vector<int>& x, vector<int>& y){
	int n = x.size();
	int X = x[0], Y = y[0];
	for(int i=1; i<n-1; i++){
		if(is_less(X, Y, x[i], y[i])){
				X = x[i];
				Y = y[i];
		}
	}
	if(X == 0) return 0;
	return Y/(long double)X;
}
 
void solve(){
	int n; cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	for(int i=0; i<n; i++) cin >> x[i] >> y[i];

	for(int i=n-1; i>=0; i--) x[i] = x[i] - x[0];
	ld res1 = find_max(x, y);
	for(int i=0; i<n; i++) x[i] = x[n-1] - x[i];
	ld res2 = find_max(x, y);

	ld res = max(res1, res2);

	cout << fixed << setprecision(10) << atan(res)*(long double)180/pi << '\n';
}
 
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}
