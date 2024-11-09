#include <bits/stdc++.h>
 
using namespace std;
 
#define debug(x) cout << #x << " = " << x << "\n"
#define sz(v) ((long long)(v).size())
#define prec(n) fixed << setprecision(n)
 
const long long N = 2e5 + 1;
const long long INF = 1e9;
const long long MOD = 1e9 + 7;
 
long long dx[] = {0, -1, 0, 1};
long long dy[] = {-1, 0, 1, 0};
 
vector<int> g[N];
vector<long long> dp(N), visited(N), st(2*N);
vector<int> a(N), id(N), order;
int timer = 0;
 
int dfs(int u) {
    id[u] = timer++;
    order.emplace_back(u);
    dp[u] = 1;
    visited[u] = 1;
    for (auto v : g[u]) {
        if (!visited[v]) dp[u] += dfs(v);
    }
    return dp[u];
}
 
void build(int idx, int l, int r) {
    if (l == r) st[idx] = a[order[l] - 1];
    else {
        int mid = (l + r) >> 1;
        build(2*idx, l, mid);
        build(2*idx + 1, mid + 1, r);
        st[idx] = st[2*idx] + st[2*idx + 1];
    }
}
 
long long query(int idx, int l, int r, int i, int j) {
    if (r < i || l > j) return 0;
    if (l >= i && r <= j) return st[idx];
    int mid = (l + r) >> 1;
    long long left = query(2*idx, l, mid, i, j);
    long long right = query(2*idx + 1, mid + 1, r, i, j);
    return left + right;
}
 
void update(int idx, int l, int r, int pos, int val) {
    if (l == r) st[idx] = val;
    else {
        int mid = (l + r) >> 1;
        if (pos <= mid) update(2*idx, l, mid, pos, val);
        else update(2*idx + 1, mid + 1, r, pos, val);
        st[idx] = st[2*idx] + st[2*idx + 1];
    }
}
 
void solve() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    int x, y;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
 
    dfs(1);
    build(1, 0, n - 1);
 
    while (q--) { 
        int type; cin >> type;
        if (type&1) {
            cin >> x >> y;
            update(1, 0, n - 1, id[x], y);
        }
        else {
            cin >> x;
            cout << query(1, 0, n - 1, id[x], id[x] + dp[x] - 1) << "\n";
        }
    }
    
}
 
int main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int tt = 1; 
    while (tt--) solve();
    
    return 0;
}
