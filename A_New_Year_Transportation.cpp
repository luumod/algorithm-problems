#include <bits/stdc++.h>

const int N=3e4+10;
int main(){
    int n,e;
    std::cin>>n>>e;
    std::vector<int> arr[N],vis(n+1,0);
    for (int i=1;i<=n;i++){
        int num;
        std::cin>>num;
        arr[i].push_back(i);
        arr[i].push_back(num+i);
    }
    bool find=false;
    std::function<void(int)> dfs=[&](int pos){
        if (pos==e){
            find=true;
            return;
        }
        for (auto& x:arr[pos]){
            int to=x;
            if (!vis[x]){
                vis[x]=true;
                dfs(x);
                vis[x]=false;
            }
        }
    };
    vis[1]=true;
    dfs(1);
    if (find){
        std::cout<<"YES\n";
    }
    else{
        std::cout<<"NO\n";
    }
	return 0;
}