#include <bits/stdc++.h>

using ll=long long;
const int N=2e3+10,INF=0x3f3f3f3f;
struct Node{
    int to,w;
};
std::vector<Node> vec[N];
ll dis[N];
int vis[N],cnt[N];
int n,m,s=1;
std::queue<int> q;
bool spfa(){
    for (int i=1;i<=n;i++){
        dis[i]=INF;
    }
    dis[s]=0;
    q.push(s);
    vis[s]=true;
    while (!q.empty()){
        auto u=q.front();
        q.pop();
        vis[u]=false; //消除当前标记
        for (auto& x:vec[u]){
            int v=x.to,w=x.w;
            if (dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                //记录松弛次数
                cnt[v]=cnt[u]+1;
                if (cnt[v]>=n){
                    //松弛超过了n次，则说明存在负环
                    return true;
                }
                if (!vis[v]){//进入队列并且标记为true
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
    return false;
}
void solve(){
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    for (auto& x:vec){
        x.clear();
    }
    std::cin>>n>>m;
    for (int i=1;i<=m;i++){
        int x,y,w;
        std::cin>>x>>y>>w;
        if (w>=0){
            vec[x].push_back({y,w});
            vec[y].push_back({x,w});
        }
        else{
            vec[x].push_back({y,w});
        }
    }
    if (spfa()){
        //存在
        std::cout<<"YES\n";
    }
    else{
        std::cout<<"NO\n";
    }
}
int main(){
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
	return 0;
}