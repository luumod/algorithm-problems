#include<bits/stdc++.h>
#if 1
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=5e4+10;
int dp[N],w[N];
int n,t;
bool check(int mid){
    //mid表示选择的空题目段长+1 
    std::deque<int> deq;
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;i++){
        if (!deq.empty() && deq.front()<i-mid){
            deq.pop_front();
        }
        while (!deq.empty() && dp[deq.back()]>=dp[i-1]){
            deq.pop_back();
        }
        deq.push_back(i-1);
        dp[i]=dp[deq.front()]+w[i];
        if (i>=n-mid+1 && dp[i]<=t){
            //mid越大，表示选择的空题目段越长，则能做的题目就越少，因此不超过t分钟的条件就越容易满足，此时返回true，更新最小值
            return true;
        }
    }
    return false;
}
signed main(){
    std::cin>>n>>t;
    for (int i=1;i<=n;i++){
        std::cin>>w[i];
    }
    //最大值最小：使得最长的空题段最短是多少
    //二分选择的 空题段长+1
    int l=-1,r=n+1;
    while (l+1<r){
        int mid=l+r>>1;
        if (check(mid)){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    std::cout<<r-1;
    return 0;
}