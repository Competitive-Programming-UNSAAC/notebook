#include<bits/stdc++.h> 
using namespace std;
 
const int N = 5e4+ 6;

vector<int> merge(vector<int> &a, vector<int> &b) {
	vector<int> aux;
	int i = 0, j = 0;
	while (i < sz(a) && j < sz(b)) {
		if (a[i] < b[j]) {
			aux.emplace_back(a[i++]);
		}
		else {
			aux.emplace_back(b[j++]);
		}
	}
	for (; i < sz(a); i++) aux.emplace_back(a[i]);
	for (; j < sz(b); j++) aux.emplace_back(b[j]);
	return aux;
}
 
vector<int> st[4*N];
int a[N];
 
void build(int idx, int l, int r) {
	if (l == r) st[idx] = {a[l]};
	else {
		int mid = (l + r) >> 1;
		build(2*idx, l, mid);
		build(2*idx + 1, mid + 1, r);
		st[idx] = merge(st[2*idx], st[2*idx + 1]);
	}
}
 
int get(vector<int> &to_search, int k) {
	int l = 0, r = sz(to_search) - 1;
	while (l <= r) {
		int mid = (l + r + 1) >> 1;
		if (to_search[mid] > k) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return sz(to_search) - (r + 1);
}
 
int query(int idx, int l, int r, int i, int j, int k) {
	if (r < i || l > j) return 0;
	if (l >= i && r <= j) return get(st[idx], k);
	int mid = (l + r) >> 1;
	int left = query(2*idx, l, mid, i, j, k);
	int right = query(2*idx + 1, mid + 1, r, i, j, k);
	return left + right;
}
 
int main() {	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
 	int n; cin >> n;
 	for (int i = 0; i < n; i++) cin >> a[i];
	build(1, 0, n - 1);
 	int q; cin >> q;
 	while (q--) {
 		int l, r, k; cin >> l >> r >> k;
 		cout << query(1, 0, n - 1, l - 1, r - 1, k) << "\n";
 	}
 	
    return 0;
}