#include <bits/stdc++.h>
 
using namespace std;
 
#define debug(x) cout << #x << " = " << x << "\n"
#define sz(v) ((long long)(v).size())
#define prec(n) fixed << setprecision(n)
 
const long long N = 1e3 + 3;
const long long INF = 1e9;
const long long MOD = 1e9 + 7;
 
long long dx[] = {0, -1, 0, 1};
long long dy[] = {-1, 0, 1, 0};
 
long long a[N][N];
vector<int> matchL(N, -1), matchR(N, -1), d(N);
vector<int> g[N];
 
int n, m;
 
bool bfs() {
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (matchL[i] == -1) {
            d[i] = 0;
            q.push(i);
        } 
        else d[i] = INF;
    }
 
    d[n] = INF;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (d[u] < d[n]) {
            for (auto v : g[u]) {
                int node = matchR[v];
                if (node == -1) {
                    d[n] = d[u] + 1;
                } 
                else if (d[node] == INF) {
                    d[node] = d[u] + 1;
                    q.push(node);
                }
            }
        }
    }
    return d[n] != INF;
}
 
bool dfs(int u) {
    if (u != -1) {
        for (auto v : g[u]) {
            int node = matchR[v];
            if (node == -1 || (d[node] == d[u] + 1 && dfs(node))) {
                matchL[u] = v;
                matchR[v] = u;
                return true;
            }
        }
        d[u] = INF;
        return false;
    }
    return true;
}
 
int hopcroftKarp() {
    int matches = 0;
    while (bfs()) {
        for (int i = 0; i < n; i++) {
            if (matchL[i] == -1 && dfs(i)) {
                matches++;
            }
        }
    }
    return matches;
}
 
bool maximumMatching(long long mid) {
    for (int i = 0; i < n; i++) g[i].clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] >= mid) {
                g[i].push_back(j);
            }
        }
    }
 
    fill(matchL.begin(), matchL.begin() + n, -1);
    fill(matchR.begin(), matchR.begin() + m, -1);
 
    return hopcroftKarp() == n;
}
 
void solve() {
    cin >> n >> m;
    long long l = 1, r = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            r = max(a[i][j], r);
        }
    }
 
    if (l == r) {
        cout << 1 << "\n";
        int xd = n;
        for (int i = 0; i < n; i++) {
            cout << xd-- << " ";
        }
    } else {
        while (l <= r) {
            long long mid = (l + r + 1) >> 1;
            if (maximumMatching(mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
 
        maximumMatching(l - 1);
        vector<int> ans(n, -1);
 
        for (int i = 0; i < m; i++) {
            if (matchR[i] != -1) {
                ans[matchR[i]] = i + 1;
            }
        }
        cout << l - 1 << "\n";
        for (auto u : ans) if (u != -1) cout << u << " ";
    }
}
 
int main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int tt = 1; 
    while (tt--) solve();
    
    return 0;
}