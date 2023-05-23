#include <bits/stdc++.h>

const int N=2e3+10;
int map[N][N];
int vis[N][N][3];
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int main(){
    int n,m;
    while (std::cin>>n>>m){
        int sx,sy;
        memset(vis,0,sizeof(vis));
        memset(map,0,sizeof(map));
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                char ch;
                std::cin>>ch;
                if (ch=='#'){
                    map[i][j]=1; //不能走为1，否则为0
                }
                else if (ch=='S'){
                    sx=i,sy=j;  //记录起点
                }
            }
        }
        bool fg=false;
        std::function<void(int,int,int,int)> dfs=[&](int x,int y,int nx,int ny){
            if (fg){
                return;
            }
            if (vis[x][y][0] && (vis[x][y][1]!=nx || vis[x][y][2]!=ny)){
                //当前点被访问过，并且[1]和[2]记录的点的坐标和第一次的时候不一样
                //说明这个点坐标和第一次访问不一致，则时第二次到达。
                fg=true;
                return;
            }
            for (int i=0;i<4;i++){
                int xx=(x+dx[i]+n)%n;
                int yy=(y+dy[i]+m)%m;
                int nnx=(nx+dx[i]);
                int nny=(ny+dy[i]);
                if (!map[xx][yy]){ //如果能走，为0时
                    if (!vis[xx][yy][0] || vis[xx][yy][1]!=nnx || vis[xx][yy][2]!=nny){
                        //记录当前点(xx,yy)第一次访问时对应的真实坐标为(nnx,nny)
                        vis[xx][yy][0]=1,vis[xx][yy][1]=nnx,vis[xx][yy][2]=nny;
                        dfs(xx,yy,nnx,nny);
                    }
                }
            }
        };
        dfs(sx,sy,sx,sy);
        if (fg){
            std::cout<<"Yes\n";
        }
        else{
            std::cout<<"No\n";
        }
    }
	return 0;
}