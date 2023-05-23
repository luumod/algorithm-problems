#include <bits/stdc++.h>

const int N=1e4+10;
std::vector<int> vec[N];
int n,m;
int dfn[N],low[N],tot;
std::stack<int> st;
int in[N];
int sz[N],scc[N],cnt;
int din[N],dout[N];
void targin(int now){
    dfn[now]=low[now]=++tot;
    st.push(now);
    in[now]=true;
    for (auto& x:vec[now]){
        if (!dfn[x]){
            targin(x);
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
            st.pop(),in[y]=false;
            scc[y]=cnt; //记录scc
        }while (y!=now);
    }
}
int main(){
    std::cin>>n;
    for (int i=1;i<=n;i++){
        int x;
        while (std::cin>>x){
            if (!x){
                break;
            }
            vec[i].push_back(x);
        }
    }
    for (int i=1;i<=n;i++){
        if (!dfn[i]){
            targin(i);
        }
    }
    /*
    1. 最少选择几个可以构成一个整体的scc: 入度为0的点的个数
    2. 添加几条线: max(din,dmx)
    */
    int ans1=0,ans2=0;
    for (int i=1;i<=n;i++){
        for (auto& x:vec[i]){
            if (scc[i]!=scc[x]){
                dout[scc[i]]++;
                din[scc[x]]++;
            }
        }
    }
    for (int i=1;i<=cnt;i++){ //遍历所有的缩点找答案
        if (!din[i]){
            ans1++;
        }
        if (!dout[i]){
            ans2++;
        }
    }
    std::cout<<ans1<<'\n';
    if (cnt==1){ //只有一个点
        std::cout<<0<<'\n';
    }
    else{
        std::cout<<std::max(ans1,ans2);
    }
    return 0;
}