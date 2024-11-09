#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x <<"\n"

const int N = 1e6;

vector<int> g[N];
vector<int> ts;
vector<int> deg(N); //degree

int main() {    
    int n, m; cin >> n >> m;
    int x, y;
    // x -> y
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        deg[y]++;
    } 
    //priority_queue<int> q; -> heap maximo
    //monticulo minimo
    priority_queue<int, vector<int>, greater<int>> q;
    
    for (int  i = 1; i <= n ; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        ts.push_back(u);
        for (auto v : g[u]) {
            deg[v]--;
            if (deg[v] == 0) {
                q.push(v);
            }
        }
    }
    
    for (auto u : ts) cout << u << " ";        
}