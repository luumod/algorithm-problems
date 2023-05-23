#include <bits/stdc++.h>

const int N=1e5+10,M=N;
int n,m;
struct Node{
    int to,next; 
}edge[M<<2];
int head[M],cnt;
int dep[N];
void add_edge(int u,int v){
    edge[++cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
void dfs(int now){
    std::queue<int> q;
    q.push(1);
    dep[1]=0;
    while (!q.empty()){
        auto u=q.front();
        q.pop();
        for (int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if (!dep[v]){
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
    }
}
int main(){
    std::cin>>n>>m;
    for (int i=1;i<n;i++){
        int a,b;
        std::cin>>a>>b;
        add_edge(a,b);
        add_edge(b,a);
    }
    dfs(1);
    int ans=0;
    for (int i=2;i<=n;i++){
        if (dep[i]<=m){
            ans++;
        }
    }
    std::cout<<ans;
    return 0;
}