vector<pair<int, int>> g[N];
vector<Long> d(N, INF), parent(N, -1);
  
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m; cin >> n >> m;
	int a, b, w;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		g[a].emplace_back(w, b);
		g[b].emplace_back(w, a);
	}
	priority_queue<pair<Long, int>> pq; //heap maximo
	d[1] = 0;
	pq.push({0, 1});
	
	while (!pq.empty()) {
		pair<Long, int> p = pq.top();
		//debug(p.ss);
		pq.pop();
		for (auto u : g[p.ss]) {
			if (d[p.ss] + (u.ff) < d[u.ss]) {
				d[u.ss] = d[p.ss] + (u.ff);
				parent[u.ss] = p.ss;
				pq.push({-d[u.ss], u.ss});
			}
		}
	} 
	int cur = n;
	vector<int> ans;
	if (d[n] == INF) cout << "-1";
	else {
		while (cur != 1) {
			ans.emplace_back(cur);
			cur = parent[cur];
		}
		ans.emplace_back(1);		
        reverse(all(ans));
		for (auto u : ans) cout << u << " ";
	}
	
	
}  