vector<int> SA(const string & s){
	int n = (int) s.size();
	vector<pair<int,int>> elem(n);
	for (int i =0; i < n; i++) elem[i] = {s[i] - 'a',i};
	sort(elem.begin(), elem.end());
	int maxk = ceil(log2(n));
	vector<pair<int,int>> c(n, {0,elem[0].second});
	for (int i = 1; i < n; i++) c[i] = {(elem[i].first != elem[i-1].first ? c[i-1].first +1 : c[i-1].first),elem[i].second};
	vector<int> co(n);
	for (int i = 0; i< n; i++) co[c[i].second] = c[i].first;
	for (int k = 0; k < maxk; k++){
		vector<pair<pair<int,int>, int>> cc(n), cco(n);
		vector<int> count(n+1,0);
		for (int i=  0; i < n; i++){
			cc[i] = {{co[i], co[(i + (1<<k))%n]},i};
			count[cc[i].first.second+1]++;
		}
		for (int i = 1; i <= n; i++) count[i] += count[i-1];
		for (int i = 0; i < n; i++) cco[count[cc[i].first.second]++] = cc[i];
		count.assign(n+1,0);
		for (int i = 0; i < n; i++) count[cco[i].first.first +1]++;
		for (int i = 1; i <= n; i++) count[i] += count[i-1];
		for (int i = 0; i< n; i++) cc[count[cco[i].first.first]++] = cco[i];
		c[0] = {0,elem[0].second};
		for (int i = 1; i < n; i++) c[i] = {cc[i].first != cc[i-1].first ? c[i-1].first +1 : c[i-1].first, cc[i].second};
		for (int i = 0; i < n; i++) co[c[i].second] = c[i].first;
 	}
 	vector<int> ans(n);
 	for (int i =0; i < n; i++) ans[i] = c[i].second;
 	return ans;
}