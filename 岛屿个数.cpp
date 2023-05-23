#include <bits/stdc++.h>
#if 0
    #define int long long
#endif
using ll=long long;

const int N=1e3+10;
int n,m;
char map[N][N];
int vis[N][N],ans;
const int dx[4]{-1,1,0,0},dy[4]{0,0,-1,1}; 
const int hdx[8]{-1,1,0,0,-1,-1,1,1},hdy[8]{0,0,-1,1,-1,1,-1,1};
void show(){
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            if (vis[i][j]){
                std::cout<<"y ";
            }
            else{
                std::cout<<"n ";
            }
        }
        std::cout<<'\n';
    }   
    std::cout<<'\n';
}
void bfs(int x,int y){
    vis[x][y]=true;
    std::queue<std::pair<int,int>> q;
    q.push({x,y});
    while (!q.empty()){
        auto p=q.front();
        q.pop();
        int px=p.first,py=p.second;
        for (int i=0;i<4;i++){
            int cx=px+dx[i],cy=py+dy[i];
            if (cx>=1 && cx<=m && cy>=1 && cy<=n && !vis[cx][cy] && map[cx][cy]=='1'){
                vis[cx][cy]=true;
                q.push({cx,cy});
            }
        }
    }
}
void dfs(int x,int y){
    vis[x][y]=true;
    for (int i=0;i<8;i++){
        int cx=x+hdx[i],cy=y+hdy[i];
        if (cx>=0 && cx<=m+1 && cy>=0 && cy<=n+1 && !vis[cx][cy]){
            if (map[cx][cy]=='1'){
                //开始深搜陆地，打标记
                bfs(cx,cy);
                ans++;
            }
            else{
                //海洋，继续深搜
                dfs(cx,cy);
            }
        }
    }
}

void solve(){
    std::cin>>m>>n; //m行n列
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            std::cin>>map[i][j];
        }
    }
    for (int i=0;i<=m+1;i++){
        map[i][0]=map[i][n+1]='0';
    }
    for (int i=0;i<=n+1;i++){
        map[0][i]=map[m+1][i]='0';
    }
    memset(vis,0,sizeof(vis));
    ans=0;
    
    dfs(0,0);
    std::cout<<ans<<'\n';
}
signed main(){
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
    return 0;
}