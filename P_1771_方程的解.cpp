#include<bits/stdc++.h>
#if 1
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=150,p=1000;
int n,k,x;
int dp[1001][101][N+10]; 
int qpow(int a,int b,int p){
    int ans=1;
    while (b){
        if (b&1){
            ans=ans*a%p;
        }
        a=a*a%p;
        b>>=1;
    }
    return ans;
}
void add(int ans[],int A[],int B[]){
    for (int i=0;i<=N;i++){
        ans[i]+=A[i]+B[i];
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
}
void solve(int nn,int mm){
    //求组合数: C(1000,100)
    for (int i=0;i<=nn;i++){
        for (int j=0;j<=i && j<=mm;j++){
            if (j==0){
                dp[i][j][0]=1;
            }
            else{
                //高精度加法
                add(dp[i][j],dp[i-1][j],dp[i-1][j-1]);
            }
        }
    }
}
signed main(){
    std::cin>>k>>x;
    n=qpow(x,x,p);
    //a1+a2+a3...+ak=n
    //正整数解组数: 满足ai>=1
    solve(n-1,k-1);
    int i=N-1;
    //跳过前导0
    while (dp[n-1][k-1][i]==0){
        i--;
    }
    while (i>=0){
        std::cout<<dp[n-1][k-1][i--];
    }
    return 0;
}