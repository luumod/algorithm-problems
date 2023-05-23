#include <bits/stdc++.h>

const int N=1e4+10;
int n,m;
std::vector<int> vec[N];
int dfn[N],low[N],tot; //编号  回溯值
std::stack<int> st;
int sz[N],scc[N],cnt,in[N];
int dout[N];
void tarjin(int now){
    dfn[now]=low[now]=++tot;
    st.push(now);
    in[now]=1;
    for (auto& x:vec[now]){
        if (!dfn[x]){
            tarjin(x);
            low[now]=std::min(low[now],low[x]);
        }
        else if (in[x]){
            low[now]=std::min(low[now],dfn[x]);
        }
    }
    if (dfn[now]==low[now]){
        int y=0;
        ++cnt;
        do{
            y=st.top();
            st.pop(),in[y]=0;
            scc[y]=cnt; 
            ++sz[cnt];  
        }while (y!=now);
    }
}
int main(){
    std::cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b;
        std::cin>>a>>b;
        vec[a].push_back(b);
    }
    for (int i=1;i<=n;i++){
        if (!dfn[i]){
            tarjin(i);
        }
    }
    //不存在出度的的缩点中所具有的点的数量就是答案
    for (int i=1;i<=n;i++){
        //记录入度: i->x
        for (auto& x:vec[i]){
            if (scc[i]!=scc[x]){
                dout[scc[i]]++; //标记出度
            }
        }
    }
    int ans=0,fg=0;
    for (int i=1;i<=cnt;i++){
        if (!dout[i]){ //找到不存在出度
            ans+=sz[i];
            ++fg;
        }
    }
    if (fg>1){
        //多个出度为0，则说明一定无法遍历到整个scc
        std::cout<<0<<'\n';
    }
    else{
        std::cout<<ans;
    }
    return 0;
}