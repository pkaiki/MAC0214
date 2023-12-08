#include<bits/stdc++.h>
#define int long long
using namespace std;

const int oo = 1e17;

int n;

struct PairComparator {
  bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const {
    if(lhs.first == rhs.first) return lhs.second < rhs.second;
    return lhs.first < rhs.first;
  }
};


struct node {
	int y, v, sum, size;
	bool rev;
	node *l, *r;
	node(int _v) : v(_v), sum(_v), y(rand()),
		size(1), l(NULL), r(NULL), rev(false) {}	
};
 
class ImplicitTreap {
private:
	node* root;
	int size(node* t) { return t ? t->size : 0; }
	int sum(node* t) { return t ? t->sum : 0; }
	node* refresh(node* t) {
		if (t == NULL) return t;
		t->size = 1 + size(t->l) + size(t->r);
		t->sum = t->v + sum(t->l) + sum(t->r);
		if (t->l != NULL) t->l->rev ^= t->rev;
		if (t->r != NULL) t->r->rev ^= t->rev;
		if (t->rev) {
			swap(t->l, t->r);
			t->rev = false;
		}
		return t;
	}
	void split(node* &t, int k, node* &a, node* &b) {
		refresh(t);
		node * aux;
		if (!t) a = b = NULL;
		else if (size(t->l) < k) {
			split(t->r, k-size(t->l)-1, aux, b);
			t->r = aux;
			a = refresh(t);
		}
		else {
			split(t->l, k, a, aux);
			t->l = aux;
			b = refresh(t);
		}
	}
	node* merge(node* a, node* b) {
		refresh(a); refresh(b);
		node* aux;
		if (!a || !b) return a ? a : b;
		if (a->y < b->y) {
			a->r = merge(a->r, b);
			return refresh(a);
		}
		else {
			b->l = merge(a, b->l);
			return refresh(b);
		}
	}
	node* at(node* t, int n) {
		if (!t) return t;
		refresh(t);
		if (n < size(t->l)) return at(t->l, n);
		else if (n == size(t->l)) return t;
		else return at(t->r, n-size(t->l)-1);
	}
	void del(node* &t) {
		if (!t) return;
		if (t->l) del(t->l);
		if (t->r) del(t->r);
		delete t;
		t = NULL;
	}
public:
	ImplicitTreap() : root(NULL) { }
	~ImplicitTreap() { clear(); }
	void clear() { del(root); }
	int size() { return size(root); }
	bool insertAt(int n, int v) {
		node *a, *b;
		split(root, n, a, b);
		root = merge(merge(a, new node(v)), b);
		return true;
	}
	bool erase(int n) {
		node *a, *b, *c, *d;
		split(root, n, a, b);
		split(b, 1, c, d);
		root = merge(a, d);
		if (c == NULL) return false;
		delete c;
		return true;
	}
	int at(int n) {
		node* ans = at(root, n);
		return ans ? ans->v : -1;
	}
	int query(int l, int r) {
		if (l > r) swap(l, r);
		node *a, *b, *c, *d;
		split(root, l, a, d);
		split(d, r-l+1, b, c);
		int ans = sum(b);
		root = merge(a, merge(b, c));
		return ans;
	}
	void reverse(int l, int r) {
		if (l>r) swap(l, r);
		node *a, *b, *c, *d;
		split(root, l, a, d);
		split(d, r-l+1, b, c);
		if (b != NULL) b->rev ^= 1;
		root = merge(a, merge(b, c));
	}
    void sortea(int l, int r){
        if(l > r) return;
        node *a, *b, *c, *d, *sas, *sus, *e, *f;
        int maximo = min(r - l, n-r);
 
 
        split(root, l, a, d);
        split(d, r - l, b, c);
        split(b, maximo, sas, sus);
        split(c, maximo, e, f);
        if(b == NULL || e == NULL) return;
        node *aux;
        swap(sas, e);
        root = merge(a, merge(merge(sas, sus), merge(e, f)));
    }
};


 
void solve(){
  ImplicitTreap treap;

  int k; cin >> n >> k;
  string s; cin >> s;

  for(int i=0; i<n; i++)
    treap.insertAt(i, s[i]);

  vector<int> l(k);
  vector<int> r(k);
  set<pair<int,int>, PairComparator> st;
  for(int i=0; i<k; i++) cin >> l[i];
  for(int i=0; i<k; i++) cin >> r[i];
  for(int i=0; i<k; i++) st.insert({l[i], r[i]});

  int q; cin >> q;

  for(int i=0; i<q; i++){
    int x; cin >> x;
    auto it = st.upper_bound({x, oo});
    it--;
    auto [l, r] = *it;
    int a = min(x, l+r-x);
    int b = max(x, l+r-x);
    treap.reverse(a-1, b-1);
  }

  for(int i=0; i<n; i++){
    cout << (char)treap.query(i, i);
  }
  cout << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
