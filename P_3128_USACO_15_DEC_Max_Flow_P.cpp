#include <bits/stdc++.h>

const int N=5e4+10,M=5e5+10,P=19;
std::vector<int> vec[N];
int n,m;
int fa[N],dep[N],top[N],son[N],sz[N];
int diff[N],sum[N];
int ans; //记录答案
void dfs1(int now,int father){
    fa[now]=father;
    dep[now]=dep[father]+1;
    sz[now]=1;
    for (auto& x:vec[now]){
        if (x!=father){
            dfs1(x,now);
            sz[now]+=sz[x];
            if (sz[son[now]]<sz[x]){
                son[now]=x;
            }
        }
    }
}
//确定top数组
void dfs2(int now,int t){
    top[now]=t;
    if (!son[now]){
        return;
    }
    dfs2(son[now],t);
    for (auto& x:vec[now]){
        if (x==fa[now] || x==son[now]){
            continue;
        }
        dfs2(x,x);
    }
}
int lca(int x,int y){
    while (top[x]!=top[y]){
        if (dep[top[x]]<dep[top[y]]){
            std::swap(x,y);
        }
        x=fa[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}
void getDiff(int now,int father){
    sum[now]+=diff[now];
    for (auto& x:vec[now]){
        if (x!=father){
            getDiff(x,now);
            sum[now]+=sum[x];
        }
    }
    ans=std::max(ans,sum[now]);
}
int main(){
    std::cin>>n>>m;
    for (int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0);
    for (int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        int p=lca(u,v);
        diff[u]++,diff[v]++,diff[p]--,diff[fa[p]]--; 
    }
    getDiff(1,0);
    std::cout<<ans;
    return 0;
}