#include <bits/stdc++.h>

int t;
int n,m,sx,sy,ex,ey;
std::string s;
void solve(){
    std::cin>>n>>m>>sx>>sy>>ex>>ey>>s;
    sx--,sy--;
    ex--,ey--;
    int dir =0;
    if (s=="DL") dir=0;
    else if (s=="UL") dir=1;
    else if (s=="DR") dir=2;
    else if (s=="UR") dir=3;
    int ans=0;
    std::vector<std::vector<std::vector<int>>> vis(n);
    for (auto& x:vis){
        x.resize(m);
        for (auto& y:x){
            y.resize(4);
        }
    }
    int i=sx,j=sy;
    while (!vis[i][j][dir]){
        int one =0;
        if (i==ex && j==ey){
            std::cout<<ans<<'\n';
            return;
        }
        if (i==0 && dir%2==1){dir-=1,one++;}
        if (i==n-1 && dir%2==0){dir+=1,one++;}
        if (j==0 && dir<2){dir+=2,one++;}
        if (j==m-1 && dir>=2){dir-=2,one++;}
        ans+=std::min(one,1);
        if (vis[i][j][dir]){
            break;
        }
        vis[i][j][dir]=1;
        if (dir%2==1) i--;
        else i++;
        if (dir<2) j--;
        else j++;
    }
    std::cout<<-1<<'\n';
}
int main(){
    std::cin>>t;
    while (t--){
        solve();
    }
	return 0;
}