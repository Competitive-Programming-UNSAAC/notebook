vector<int> kasai(vector<int> & sa, string & s){
	int n = (int) s.length();
	vector<int> isa = sa;
	for (int i = 0; i < sa.size(); i++) isa[sa[i]] = i;
	vector<int> lcp(n,0);
	int k = 0;
	for (int i = 0; i < n-1; i++){
		int sai = isa[i];
		int j = sa[sai-1];
		while ((i + k < n && j + k < n) && (s[i+k] == s[j+k])) k++;
		lcp[sai] = k;
		k = max(0,k-1);
	}
	return lcp;
}