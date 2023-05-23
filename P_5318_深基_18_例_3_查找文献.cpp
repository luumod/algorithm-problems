#include <bits/stdc++.h>

const int N=1e5+10;
std::vector<int> arr[N],vis(N,0);
int main(){
    int n,m;
    std::cin>>n>>m;
    for (int i=1;i<=m;i++){
        int x,y;
        std::cin>>x>>y;
        arr[x].push_back(y);
    }
    for (auto& vec:arr){
        std::sort(vec.begin(),vec.end());
    }
    std::function<void(int)> dfs=[&](int now){
        vis[now]=true;
        std::cout<<now<<' ';
        for (auto& x:arr[now]){
            if (!vis[x]){
                dfs(x);
            }
        }
    };
    std::function<void()> bfs=[=](){
        std::queue<int> q;
        std::cout<<1<<' ';
        q.push(1);
        vis[1]=true;
        while (!q.empty()){
            auto p = q.front();
            q.pop();
            for (auto &x:arr[p]){
                if (!vis[x]){
                    q.push(x);
                    std::cout<<x<<' ';
                    vis[x]=true;
                }
            }
        }
    };  
    dfs(1);
    std::cout<<'\n';
    std::fill(vis.begin(),vis.begin()+1+n,0);
    bfs();
	return 0;
}