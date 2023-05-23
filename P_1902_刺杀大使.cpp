#include <bits/stdc++.h>

const int N=1010;
int map[N][N],vis[N][N];
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int main(){
    int n,m;
    std::cin>>n>>m;
    int mx=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            std::cin>>map[i][j];
            mx=std::max(mx,map[i][j]);
        }
    }
    std::function<bool(int,int,int)> dfs=[&](int x,int y,int mid){
        if (x==n){
            //到达第n行
            return true;
        }
        vis[x][y]=true;
        for (int i=0;i<4;i++){
            int cx=x+dx[i],cy=y+dy[i];
            if (cx>=1 && cx<=n && cy>=1 && cy<=m && !vis[cx][cy] && map[cx][cy]<=mid){
                if (dfs(cx,cy,mid)){
                    return true; //到达终点
                }
            }
        }
        return false; //没有到达
    };
    //二分最大可承受伤害值，如果在这个伤害值下能走到第n行，则返回true，否则返回false，寻找一个最小的伤害值即可
    int l=0,r=1010;
    while (l+1<r){
        int mid=l+r>>1;
        memset(vis,0,sizeof(vis));
        if (dfs(1,1,mid)){
            r=mid; //寻找最小值
        }
        else{
            l=mid;
        }
    }
    std::cout<<r;
	return 0;
}