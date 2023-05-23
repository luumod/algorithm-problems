#include <bits/stdc++.h>

const int N=1e4+10;
int n,m;
int val[N];
std::vector<int> vec[N];
int dfn[N],low[N],tot;
std::stack<int> st;
int sz[N],scc[N],cnt,in_stk[N];
std::vector<int> topo[N];
int dp[N],nval[N]; //ans
//tarjan缩点：转换为有向无环图
void tarjin(int now){
    dfn[now]=low[now]=++tot;
    st.push(now);
    in_stk[now]=true;
    for (auto& x:vec[now]){
        if (!dfn[x]){
            tarjin(x);
            low[now]=std::min(low[now],low[x]);
        }
        else if (in_stk[x]){
            low[now]=std::min(low[now],dfn[x]);
        }
    }
    if (dfn[now]==low[now]){
        int y=0;
        ++cnt;
        do
        {
            y=st.top();
            st.pop(),in_stk[y]=false;
            scc[y]=cnt;
            ++sz[cnt];
        } while (y!=now);
    }
}
signed main(){
    std::cin>>n>>m;
    for (int i=1;i<=n;i++){
        std::cin>>val[i];
    }
    for (int i=1;i<=m;i++){
        int x,y;
        std::cin>>x>>y;
        vec[x].push_back(y);
    }
    for (int i=1;i<=n;i++){
        if (!dfn[i]){
            tarjin(i);
        }
    }
    //缩点转化为逆序的有向无环图
    //构造DAG的topo序
    for (int i=1;i<=n;i++){
        nval[scc[i]]+=val[i]; //某缩点的总权值
        for (auto& x:vec[i]){
            if (scc[i]!=scc[x]){
                topo[scc[i]].push_back(scc[x]); //对缩点进行建图
            }
        }
    }
    int ans=0;
    for (int i=cnt;i>=1;i--){ //倒序遍历cnt个缩点
        if (!dp[i]){
            dp[i]=nval[i];
        }
        for (auto& x:topo[i]){
            dp[x]=std::max(dp[x],dp[i]+nval[x]);
        }
    }
    for (int i=1;i<=cnt;i++){
        ans=std::max(ans,dp[i]);
    }
    std::cout<<ans;
    return 0;
}