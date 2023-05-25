#include<bits/stdc++.h>
#if 0
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}


const int N=150;
int n;
int a[N][N],t[N];
int dp[N];
int get1(){
    int res=0;
    for (int j=1;j<=n;j++){
        //一维最大子序列和
        dp[j]=std::max(dp[j-1],0)+t[j];
        //std::cout<<dp[j]<<" \n"[j==n];
        res=std::max(res,dp[j]);
    }
    return res;
}
signed main(){
    std::cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            std::cin>>a[i][j];
        }
    }
    int res=-1e9;
    for (int z=1;z<=n;z++){
        memset(t,0,sizeof(t));
        //累加
        for (int i=z;i<=n;i++){
            for (int j=1;j<=n;j++){
                t[j]+=a[i][j];
            }
            res=std::max(res,get1());
        }
        //计算最大连续子序列和
    }
    std::cout<<res;
    return 0;
}