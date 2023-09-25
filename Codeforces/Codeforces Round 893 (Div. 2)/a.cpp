#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl
#define rep(i,n) for (int i = 0; i < (n); i++)
#define per(i,n) for (int i = (n)-1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

void solve(){
	ll a, b, c; cin >> a >> b >> c;
	ll ana = a + c-c/2;
	ll katie = b + c/2;
	if(katie >= ana){
		cout << "Second\n";
		return;
	}
	else{
		cout << "First\n"; 
		return;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll t; cin >> t;
	while(t--) solve(); return 0;
}
