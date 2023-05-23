#include <bits/stdc++.h>

const int N=1e5+10;
std::vector<int> arr[N];
int main(){
    int n;
    std::cin>>n;
    std::vector<int> in(n+1);
    std::vector<int> val(n+1),ans(n+1);
    for (int i=1;i<=n;i++){
        int num,x;
        std::cin>>num>>val[i];
        while (std::cin>>x){
            if (x==0){
                break;
            }
            arr[x].push_back(num);
            in[num]++; //记录入度+1
        }
    }   
    std::queue<int> q;
    //1. 取出入度为0的点
    for (int i=1;i<=n;i++){
        if (in[i]==0){
            q.push(i); //入度为0的点加入到队列
            ans[i]=val[i];
        }
    }
    //2. 进行拓扑排序
    while (!q.empty()){
        int u=q.front(); //取出当前点
        q.pop();
        for (auto &x:arr[u]){//遍历其所有出度
            in[x]--; //对应点的入度-1
            if (in[x]==0){ //如果对应点入度为0，则加入队列
                q.push(x);
            }
            ans[x]=std::max(ans[x],ans[u]+val[x]);//dp寻找答案
        }
    }
    int res=0;
    for (int i=1;i<=n;i++){
        res=std::max(res,ans[i]);
    }
    std::cout<<res;
	return 0;
}