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
int n,m,ans;
int vis[N][N];
const int dx[4]={-2,-1,1,2},dy[4]={1,2,2,1};
void dfs(int x,int y){
    if (x==n && y==m){
        ans++;
        return;
    }
    for (int i=0;i<4;i++){
        int cx=x+dx[i],cy=y+dy[i];
        if (cx>=n && cx<=2*n && cy>=0 && cy<=m && !vis[cx][cy]){
            vis[cx][cy]=true;
            dfs(cx,cy);
            vis[cx][cy]=false;
        }
    }
}
signed main(){
    std::cin>>n>>m;
    int sx=2*n,sy=0;
    vis[sx][sy]=true;
    dfs(sx,sy);
    std::cout<<ans;
    return 0;
}