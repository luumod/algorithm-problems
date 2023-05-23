#include <bits/stdc++.h>

const int N=6e3+10;
int n;
std::vector<int> V(N);
std::vector<int> tree[N];
int dp[N][2]; //dp[i][0]：当前人不参加 dp[i][1]当前人参加
void dfs(int now){
    dp[now][1]=V[now];
    for (auto& son:tree[now]){
        dfs(son);
        dp[now][0]+=std::max(dp[son][0],dp[son][1]); //当前人不参加，直系下属可以参加，也可以不参加
        dp[now][1]+=dp[son][0];//当前人参加，直系下属一定不参加
    }
}
int main(){
    std::cin>>n;
    for (int i=1;i<=n;i++){
        std::cin>>V[i];
    }
    int root=0;
    std::vector<bool> hasFa(n+1);
    for (int i=1;i<n;i++){
        int me,fa;
        std::cin>>me>>fa;
        tree[fa].push_back(me);
        hasFa[me]=true;
    }
    for (int i=1;i<=n;i++){
        if (!hasFa[i]){
            root=i;
        }
    }
    dfs(root);
    std::cout<<std::max(dp[root][0],dp[root][1]);
	return 0;
}