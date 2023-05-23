#include <bits/stdc++.h>
#if 0
    #define int long long
#endif
using ll=long long;
#define l std::cout<<'\n'
#define io std::ios::sync_with_stdio(false),std::cin.tie(nullptr);
template <typename T1=int,typename T2=int>
using ump=std::unordered_map<T1,T2>;
template <typename T=int>
using ust=std::unordered_set<T>;

const int N=1e3+10;
int n,m,t,sx,sy,ex,ey;
int za[N][N],ans,vis[N][N];
const int dx[4]{-1,1,0,0},dy[4]{0,0,-1,1};
void dfs(int x,int y){
    if (x==ex && y==ey){
        ans++;
        return;
    }
    for (int i=0;i<4;i++){
        int cx=x+dx[i],cy=y+dy[i];
        if (cx>=1 && cx<=n && cy>=1 && cy<=m && !za[cx][cy] && !vis[cx][cy]){
            vis[cx][cy]=true;
            dfs(cx,cy);
            vis[cx][cy]=false;
        }
    }
}
signed main(){
    std::cin>>n>>m>>t;
    std::cin>>sx>>sy>>ex>>ey;
    for (int i=1;i<=t;i++){
        int x,y;
        std::cin>>x>>y;
        za[x][y]=1;
    }
    vis[sx][sy]=true;
    dfs(sx,sy);
    std::cout<<ans;
    return 0;
}