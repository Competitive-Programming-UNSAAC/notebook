#include<bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << #x << " = " << x << "\n"
const int N = 1e6 + 10;
const long long INF = 1e9;
 
vector<long long> ft(N), a(N);
int n;
int query(int i) { // sum [1, i] 
    int sum = 0;
    for (; i > 0; i -= i&-i) {
        sum += ft[i];
    }
    return sum;
}
 
void update(int i, int value) {
    for (; i <= n; i += i&-i) {
        ft[i] += value;
    }
}
 
int getKth(int k) {
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r + 1) >> 1;
        if (query(mid) >= k) {
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return r + 1;
}
 
void solve() {
    int q; cin >> n >> q;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x; 
        update(x, 1);
    }
    
    while (q--) {
        cin >> x;
        if (x < 0) {
            x *= -1;
            int idx = getKth(x);
            update(idx, -1);
        }
        else {
            update(x, 1);
        }
    }
    cout << (getKth(1) == n + 1? 0 : getKth(1)) << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int tt = 1; //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
