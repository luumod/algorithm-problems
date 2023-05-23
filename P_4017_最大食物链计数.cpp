#include <bits/stdc++.h>

const int N=5e3+10,mod=80112002;
std::vector<int> arr[N];
int main(){
    int n,m;
    std::cin>>n>>m;
    std::vector<int> in(n+1),out(n+1),ans(n+1);
    for (int i=1;i<=m;i++){
        int a,b; //b吃a
        std::cin>>a>>b;
        arr[b].push_back(a);
        in[a]++;  //记录消费者
        out[b]++; //记录最低级生产者
    }
    std::queue<int> q;
    for (int i=1;i<=n;i++){
        if (in[i]==0){ //最顶级消费者
            q.push(i); 
            ans[i]=1;
        }
    }
    while (!q.empty()){
        int u=q.front();
        q.pop();
        for (auto& x:arr[u]){
            in[x]--;
            if (in[x]==0){
                q.push(x);
            }
            ans[x]=(ans[x]+ans[u])%mod; //最低级消费者
        }
    }
    long long res=0;
    for (int i=1;i<=n;i++){
        if (!out[i]){ //最低级生产者
            res=(res+ans[i])%mod;
        }
    }
    std::cout<<res;
	return 0;
}