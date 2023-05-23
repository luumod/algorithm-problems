#include <bits/stdc++.h>

using ll=long long;
const int N=5e4+10;
int n;
std::vector<int> vec[N];
int ans=1e9,id;
int vis[N],dis[N],U[N],V[N];
//求树的重心
int dfs(int now){
    vis[now]=true;
    int mxsize=0;
    int cursize=1;
    for (auto& x:vec[now]){
        if (!vis[x]){
            int num=dfs(x); //返回孩子节点的子树的节点数
            mxsize=std::max(mxsize,num); //维护最大孩子节点的节点数
            cursize+=num; //累加当前子树的节点数
        }
    }
    int s=std::max(n-cursize,mxsize);
    if (ans>s || (ans==s && id>now)){
        ans=s;
        id=now;
    }
    return cursize;
}  
void bfs(int s){
    memset(dis,0,sizeof(dis));
    std::queue<int> q;
    q.push(s);
    dis[s]=1;
    while (!q.empty()){
        auto u=q.front();
        q.pop();
        for (auto& x:vec[u]){
            if (!dis[x]){
                dis[x]=dis[u]+1;
                q.push(x);
            }
        }
    }
}
int main(){
    std::cin>>n;
    for (int i=1;i<n;i++){
        std::cin>>U[i]>>V[i];
        vec[U[i]].push_back(V[i]);
        vec[V[i]].push_back(U[i]);
    }
    dfs(1);
    ans=0;

    bfs(id);
    for (int i=1;i<=n;i++){
        ans+=(dis[i]-1);
    }
    std::cout<<id<<' '<<ans;
    return 0;
}