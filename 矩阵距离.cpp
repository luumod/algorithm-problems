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
int n,m;
char map[N][N];
int dis[N][N];
const int dx[8]{-1,1,0,0},dy[8]{0,0,-1,1};
void bfs(){
    memset(dis,-1,sizeof(dis));
    std::queue<std::pair<int,int>> q;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (map[i][j]=='1'){
                q.push({i,j});
                dis[i][j]=0;   
            }
        }
    }
    
    while (!q.empty()){
        auto p=q.front();
        q.pop();
        for (int i=0;i<8;i++){
            int cx=p.first+dx[i],cy=p.second+dy[i];
            if (cx>=1 && cx<=n && cy>=1 && cy<=m && dis[cx][cy]==-1){
                dis[cx][cy]=dis[p.first][p.second]+1;
                q.push({cx,cy});
            }
        }
    }
}
signed main(){
    std::cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            std::cin>>map[i][j];
        }
    }
    bfs();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            std::cout<<dis[i][j]<<' ';
        }
        l;
    }   
    return 0;
}