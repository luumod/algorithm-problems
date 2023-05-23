#include <bits/stdc++.h>

const int N=110;
std::vector<int> vec[N];
std::vector<int> ans;
int fg[N];
int n,m;
bool dfs(int i){
    fg[i]=-1; //走过的点标记为-1
    for (auto& x:vec[i]){
        if (fg[x]<0){
            //是一个环，之前出现过
            return false;
        }
        else if (!fg[x]){
            //为0说明之前未出现过
            if (!dfs(x)){ //染色
                return false;
            }
        }
    }
    fg[i]=1; //正确的点，标记为1然后加入答案(倒序，最后需要reverse)
    ans.push_back(i);
    return true;
}
bool solve(){
    for (int i=1;i<=n;i++){
        if (!fg[i]){
            //如果没有被标记过
            if (!dfs(i)){
                return false; //有环
            }
        }   
    }
    std::reverse(ans.begin(),ans.end());
    for (auto &x:ans){
        std::cout<<x<<' ';
    }
    std::cout<<'\n';
    return true;
}
int main(){
    while (std::cin>>n>>m){
        if (n==0 && m==0){
            break;
        }
        memset(fg,0,sizeof(fg));
        ans.clear();
        for (auto& x:vec){
            x.clear();
        }
        for (int i=1;i<=m;i++){
            int x,y;
            std::cin>>x>>y;
            vec[x].push_back(y);
        }
        solve();
    }
	return 0;
}