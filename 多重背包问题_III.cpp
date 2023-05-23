#include <bits/stdc++.h>

int main(){
    int n,m;
    std::cin>>n>>m; //种类和背包容量    
    std::vector<int> dp(m+1),temp(m+1);
    int w,v,s;
    for (int i=1;i<=n;i++){
        std::copy(dp.begin()+1,dp.begin()+1+m,temp.begin()+1);
        std::cin>>w>>v>>s;//体积  价值  数量
        for (int j=0;j<w;j++){//分成w组
            std::deque<int> deq;
            for (int k=j;k<=m;k+=w){//对每组进行单调队列
                if (!deq.empty() && deq.front()<k-s*w){
                    deq.pop_front();
                }
                if (!deq.empty()){
                    dp[k]=std::max(temp[k],temp[deq.front()]+(k-deq.front())/w*v);
                }
                //当前k比队尾元素更具有价值，则更新
                while (!deq.empty() && temp[k]>=temp[deq.back()]+(k-deq.back())/w*v){
                    deq.pop_back();
                }
                deq.push_back(k);
            }
        }
    }
    std::cout<<dp[m];
	return 0;
}