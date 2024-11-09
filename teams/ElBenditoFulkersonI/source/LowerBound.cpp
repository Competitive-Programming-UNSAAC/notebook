#include <bits/stdc++.h>
 
using namespace std;
 
#define debug(x) cout << #x << " = " << x << "\n"
const int N = 1e5 + 10;
const long long INF = 1e9;
const int MOD = 1e9 + 7;
 
long long st[4*N], a[N];
 
void build(int idx, int l, int r) {
    if (l == r) st[idx] = a[l];    
    else {
        int mid = (l + r) >> 1;
        build(2*idx, l, mid);
        build(2*idx + 1, mid + 1, r);
        st[idx] = max(st[2*idx], st[2*idx + 1]);
    }
}
 
void update(int idx, int l, int r, int pos, long long val) {
    if (l == r) st[idx] = val;
    else {
        int mid = (l + r) >> 1;
        if (pos <= mid) update(2*idx, l, mid, pos, val);
        else update(2*idx + 1, mid + 1, r, pos, val);
        st[idx] = max(st[2*idx], st[2*idx + 1]);
    }
}
 
int query(int idx, int l, int r, int x, int i) { 
    if (l == r) {
        if (st[idx] < x) return -1;
        else return l;
    }
    int mid = (l + r) >> 1;
    int left = -1, right = -1;
    
    if (mid >= i && st[2*idx] >= x) {
        left = query(2*idx, l, mid, x, i);
    }
    if (left == -1) {
            right = query(2*idx + 1, mid + 1, r, x, i);
    }
    return max(left, right);
}
 
void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n - 1);
    
    while (m--) {
        int type, index, val; cin >> type;
 
        if (type&1) {
            cin >> index >> val;
            update(1, 0, n - 1, index, val);
        }
        else {
            cin >> val >> index;
            cout << query(1, 0, n - 1, val, index) << "\n";
        }
    }
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
 
    int tt = 1; //cin >> tt;
    while (tt--){
        solve();
    }
    return 0;
}
