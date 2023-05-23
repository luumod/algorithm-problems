#include <bits/stdc++.h>

const int N=2e4+10;
int n,m;
std::vector<int> vec[N];
std::stack<int> st;
int dfn[N],low[N]; //时间戳 追溯值
bool in[N];  //是否在栈中
int tot,cnt; 
int scc[N],sz[N]; //统计
//tarjan求强连通分量
void tarjan(int now){
    //入时：记录事件戳，记录当前点的回溯值
    dfn[now]=low[now]=++tot;
    //入栈
    st.push(now);
    in[now]=1; //标记此点在栈中，可以构成scc
    for (auto &x:vec[now]){
        if (!dfn[x]){ //没有访问过
            tarjan(x);
            //更新回溯值
            low[now]=std::min(low[now],low[x]);
        }
        else if (in[x]){ //访问过了，并且在栈中
            low[now]=std::min(low[now],dfn[x]);
        }
    }
    //当前编号等于根，说明是一个scc，因为scc所处的根节点的回溯值点与当前点是相同的
    if (dfn[now]==low[now]){
        int y=0;
        ++cnt;
        do{
            y=st.top();
            st.pop(),in[y]=0;
            scc[y]=cnt; //记录强连通分量的点
            ++sz[cnt];  //累加个数
        } while (y!=now);
    }
}
int main(){
    std::cin>>n>>m;
    for (int i=1;i<=m;i++){
        int x,y;
        std::cin>>x>>y;
        vec[x].push_back(y);
    }
    for (int i=1;i<=n;i++){
        if (!dfn[i]){
            tarjan(i);
        }
    }
    int ans=0;
    for (int i=1;i<=cnt;i++){
        if (sz[i]>1){
            ans++;
        }
    }
    std::cout<<ans;
    return 0;
}