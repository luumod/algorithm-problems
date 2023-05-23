#include <bits/stdc++.h>

const int N=1010;
int map[N][N];
const int dx[4]{-1,1,0,0},dy[4]{0,0,-1,1};
int dp[N][N];
int n,m;
bool vis[N][N];
int ans=0;
int dfs(int x,int y){
    vis[x][y]=true;
    int sum=map[x][y];
    for (int i=0;i<4;i++){
        int cx=x+dx[i],cy=y+dy[i];
        if (cx>=1 && cx<=n &&cy>=1 && cy<=m && !vis[cx][cy] && map[cx][cy]){
            sum+=dfs(cx,cy);
        }
    }
    return sum;
}
void solve(){
    std::cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            std::cin>>map[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    int res=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (map[i][j] && !vis[i][j]){
                res=std::max(res,dfs(i,j));
            }
        }
    }
    std::cout<<res<<'\n';
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}