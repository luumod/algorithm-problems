#include<bits/stdc++.h>
#if 1
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=1e5+10;
int p,n,m,t;
int f[N],g[N]; //阶乘 逆元
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
void init(int p){
    f[0]=g[0]=1;
    for (int i=1;i<=p;i++){
        f[i]=f[i-1]*i%p;
        g[i]=g[i-1]*qpow(i,p-2,p)%p;
    }   
}
int get(int n,int m,int p){
    return f[n]*g[n-m]%p*g[m]%p;
}
int lucas(int n,int m,int p){
    if (m==0){
        return 1;
    }
    return lucas(n/p,m/p,p)*get(n%p,m%p,p)%p;
}
int solve(int n,int m,int p){
    init(p);
    return lucas(n,m,p);
}
signed main(){
    std::cin>>t;
    while (t--){
        std::cin>>n>>m>>p;
        std::cout<<solve(n+m,n,p)<<'\n';
    }
    return 0;
}