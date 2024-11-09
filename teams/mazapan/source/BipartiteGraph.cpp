vector<int> g[N], color(N, -1);

int main() {
	int n, m; cin >> n >> m;
	int a, b;
	
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	
	queue<int> q;
	bool ok = 1;
	
	for (int i = 1; i <= n; i++) {
		if (color[i] == -1) {
			q.push(i);
			color[i] = 0;
			while (!q.empty() && ok) {
				int u = q.front();
				q.pop();
				for (auto v : g[u]) {
					if (color[v] == -1) {
						color[v] = color[u]^1;
						q.push(v);
					}
					else if (color[u] == color[v]) {
						ok = 0;
						break;
					}
				}
			}
		}
	}
	cout << (ok? "Is Bipartite" : "Isn't Bibartite");
	
	return 0;
}