#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> num(n+1),g(n+1);
    std::set<int,std::less<int>> nz,gz;
    int last=0;
    for (int i=1;i<=n;i++){
        std::cin>>num[i];
        nz.insert(num[i]);
        last=std::max(last,num[i]);
    }
    for (int i=1;i<=n;i++){
        std::cin>>g[i];
        gz.insert(g[i]);
    }
    std::unordered_map<int,int> ump[1010];
    for (int i=1;i<=n;i++){
        ump[g[i]][num[i]]++;
    }
    for (auto& x:gz){
        std::cout<<x<<"={";
        for (auto& y:nz){
            std::cout<<y<<"=";
            std::cout<<ump[x][y];
            if (y!=last){
                std::cout<<",";
            }
        }
        std::cout<<"}\n";
    }
    std::cout<<'\n';
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}