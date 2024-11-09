// mobius function
namespace mobius{
    vector<int> get(int n){
        vector<int> ret(n+1),vis(n+1);
        vector<int> prime;
        ret[1] = 1;
        for (int i=2;i<=n;i++){
            if (!vis[i]){
                prime.push_back(i);
                ret[i] = -1;
            }
            for (auto& p:prime){
                if (p*i>n){break;}
                vis[p*i] = 1;
                if (i%p==0){
                    ret[p*i] = 0;
                    break;
                }else{
                    ret[p*i] = -ret[i];
                }
            }
        }
        return ret;
    }
}