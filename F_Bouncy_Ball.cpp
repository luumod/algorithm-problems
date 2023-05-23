#include <bits/stdc++.h>

void solve(){
    int n,m,x,y,xx,yy;
    std::string d;
    std::cin>>n>>m>>x>>y>>xx>>yy>>d;
    /*
    对方向进行分类:
    UL UR 如果无法往上走，则只需要-1 就可以变为 DL DR
    UL DL 如果无法往左走，则只需要+2 就可以变为 UR DR

    UL UR DL DR
    1  3  0  2
    */
    x--,y--;
    xx--,yy--;
    int i = x , j =y;
    int cnt=0;
    int dir = (d[0]=='U'?1+(d[1]=='L'?0:2):0+(d[1]=='L'?0:2));
    std::vector<std::vector<std::vector<int>>> vis(n);
    for (auto &x:vis){
        x.resize(m);
        for (auto &y:x){
            y.resize(4);
        }   
    }
    while (!vis[i][j][dir]){
        int one = 0;
        if (i==xx && j==yy){
            std::cout<<cnt<<'\n';
            return;
        }
        if (i==0 && dir%2==1){
            dir--;
            one++;
        }
        if (i==n-1 && dir%2==0){
            dir++;
            one++;
        }
        if (j==0 && dir<2){
            dir+=2;
            one++;
        }
        if (j==m-1 && dir>=2){
            dir-=2;
            one++;
        }
        cnt += std::min(one,1);
        if (vis[i][j][dir]){
            break;
        }
        vis[i][j][dir]=1;
        if (dir%2==1){
            i--;
        }
        else{
            i++;
        }
        if (dir<2){
            j--;
        }
        else{
            j++;
        }
    }
    std::cout<<-1<<'\n';
}
int main(){
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
	return 0;
}