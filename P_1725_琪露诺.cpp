#include<bits/stdc++.h>
#if 0
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=2e5+10;
int n,l,r;
int w[N],dp[N];
std::deque<int> deq;
signed main(){
    std::cin>>n>>l>>r;
    for (int i=0;i<=n+1;i++){
        std::cin>>w[i];
    }
    //i可以跳跃到[i+l,i+r]中的任意位置
    //同理i位置可以由[i-r,i-l]区间中任意位置跳跃过来，维护窗口中的最大值即可
    memset(dp,-0x3f,sizeof(dp));
    dp[0]=0;
    int ans=-1e9;
    //注意从l开始，因为一开始只能跳到[l,r]的位置
    for (int i=l;i<=n;i++){
        if (!deq.empty() && deq.front()<i-r){
            deq.pop_front();
        }
        //维护单调队列最大值
        while (!deq.empty() && dp[deq.back()]<=dp[i-l]){
            deq.pop_back();
        }
        deq.push_back(i-l);
        dp[i]=dp[deq.front()]+w[i];
        if (i>=n-r+1){
            ans=std::max(ans,dp[i]); //在最后的区间内累加答案
        }
    }
    std::cout<<ans;
    return 0;
}