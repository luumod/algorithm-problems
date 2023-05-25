#include<bits/stdc++.h>
#if 0
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=5e3+10;
int t,maxp,w;
int ap,bp,as,bs;
int dp[N][N]; //dp[i][j]表示第i天持股j时的最大价值
signed main(){
    memset(dp,-0x3f,sizeof(dp));
    std::cin>>t>>maxp>>w; //t天，持股不能超过maxp，交易间隔w天
    for (int i=1;i<=t;i++){
        //买入价ap，卖出价bp，最多买入as，最多卖出bs
        std::cin>>ap>>bp>>as>>bs;   
        //凭空买入
        for (int j=0;j<=as;j++){
            dp[i][j]=-ap*j;
        }
        //不买不卖
        for (int j=0;j<=maxp;j++){
            dp[i][j]=std::max(dp[i][j],dp[i-1][j]);
        }
        if (i<=w){
            continue;
        }
        //买入
        std::deque<int> deq;
        for (int j=0;j<=maxp;j++){
            if (!deq.empty() && deq.front()<j-as){
                deq.pop_front();
            }
            while (!deq.empty() && dp[i-w-1][deq.back()]+deq.back()*ap-j*ap<=dp[i-w-1][j]){
                deq.pop_back();
            }       
            deq.push_back(j);
            dp[i][j]=std::max(dp[i][j],dp[i-w-1][deq.front()]-ap*(j-deq.front()));
        }
        deq.clear();
        //卖出
        for (int j=maxp;j>=0;j--){
            if (!deq.empty() && deq.front()>j+bs){
                deq.pop_front();
            }
            while (!deq.empty() && dp[i-w-1][deq.back()]+deq.back()*bp-j*bp<=dp[i-w-1][j]){
                deq.pop_back();
            }
            deq.push_back(j);
            dp[i][j]=std::max(dp[i][j],dp[i-w-1][deq.front()]+bp*(deq.front()-j));
        }
    }
    std::cout<<dp[t][0];
    return 0;
}