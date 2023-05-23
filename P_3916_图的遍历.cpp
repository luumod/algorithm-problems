#include <bits/stdc++.h>

const int N=1e5+10;
std::vector<int> arr[N];
int main(){
    int n,m;
    std::cin>>n>>m;
    for (int i=1;i<=m;i++){
        int x,y;
        std::cin>>x>>y;
        arr[y].push_back(x);
    }
    std::vector<int> ans(n+1,0);
    std::function<void(int,int)> dfs=[&](int now,int w){
        if (ans[now]){
            return;
        }
        ans[now]=w;
        for (auto& x:arr[now]){
            if (!ans[x]){
                dfs(x,w); //w表示当前最大的i（反向）
            }
        }
    };
    for (int i=n;i>=1;i--){
        dfs(i,i);
    }
    for (int i=1;i<=n;i++){
        std::cout<<ans[i]<<' ';
    }
	return 0;
}