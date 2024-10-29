int n,k; cin>>n>>k;
set<int> no;
for (int i = 1; i <= n; i++) no.insert(i);
vector<set<int>> co(n+1);
while(k--){
    int x,y; cin>>x>>y;
    co[x].insert(y);
    co[y].insert(x);
}
vector<vector<int>> comp;
while (!no.empty()){
    queue<int> q; q.push(*no.begin());
    no.erase(no.begin());
    vector<int> del;
    vector<int> elements;
    elements.push_back(q.front());
    while(!q.empty()){
        int ve = q.front(); q.pop();
        vector<int> del;
        for (auto u: no){
            if (co[ve].find(u) == co[ve].end()){
                del.push_back(u);
                q.push(u);
                elements.push_back(u);
            }
        }
        for (auto x: del) no.erase(no.find(x));
    }
    comp.push_back(elements);
}