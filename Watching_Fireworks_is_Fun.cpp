#include<bits/stdc++.h>
#if 1
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=150010;
int dp[2][N]; //滚动数组: dp[i][j]表示放第i个烟花，当前位置位于j时的最大快乐值
int n,m,d;
int a[N],b[N],t[N];
signed main(){
    std::cin>>n>>m>>d;
    for (int i=1;i<=m;i++){
        std::cin>>a[i]>>b[i]>>t[i];
    }
    memset(dp,-0x3f,sizeof(dp));
    for (int i=1;i<=n;i++){
        dp[0][i]=0;  //初始化，放第0个烟花，位置在任何时刻都是0快乐度
    }
    //遍历烟花
    for (int z=1;z<=m;z++){
        //now表示当前，pre表示上一个
        int now=z&1,pre=(z-1)&1;
        std::deque<int> deq;
        //遍历位置：窗口往右滑动
        for (int i=1;i<=n;i++){
            if (!deq.empty() && deq.front()<i-d*(t[z]-t[z-1])){
                deq.pop_front();
            }
            //维护队列最大值
            while (!deq.empty() && dp[pre][deq.back()]<=dp[pre][i]){
                deq.pop_back();
            }
            deq.push_back(i);
            dp[now][i]=dp[pre][deq.front()]+b[z]-abs(a[z]-i);
        }
        //窗口往左滑动
        for (int i=n;i>=1;i--){
            if (!deq.empty() && deq.front()>i+d*(t[z]-t[z-1])){
                deq.pop_front();
            }
            while (!deq.empty() && dp[pre][deq.back()]<=dp[pre][i]){
                deq.pop_back();
            }
            deq.push_back(i);
            dp[now][i]=std::max(dp[now][i],dp[pre][deq.front()]+b[z]-abs(a[z]-i));
        }
    }
    int ans=-1e18;
    //最后一次在m&1，位置为j时枚举一个最大值
    for (int i=1;i<=n;i++){
        ans=std::max(dp[m&1][i],ans);
    }
    std::cout<<ans;
    return 0;   
}