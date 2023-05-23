#include <bits/stdc++.h>
#if 0
    #define int long long
#endif
using ll=long long;

const int N=1e3+10;
int n,m;
int must[N];
struct Node{
    int to,next,w;
}edge[N<<2];
int head[N],cnt;
int dis[N],vis[N],dp[N][N];
std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> q;
void add_edge(int u,int v,int w=0){
    edge[++cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
void floyd(){
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dp[i][j]=std::min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
}
signed main(){
    std::cin>>n>>m;
    for (int i=1;i<=m;i++){
        std::cin>>must[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int v;
            std::cin>>v;
            if (i==j){
                continue;
            }
            //add_edge(i,j,v);
            dp[i][j]=v;
        }
    }
    floyd();
    int ans=0;
    for (int i=1;i<m;i++){
        ans+=dp[must[i]][must[i+1]];
    }
    std::cout<<ans;
    return 0;
}