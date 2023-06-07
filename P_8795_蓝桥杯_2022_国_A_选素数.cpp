#include<bits/stdc++.h>
#if 1
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=1e6+10;
int primes[N+10],f[N+10];
std::vector<int> fg(N+10,false);
int n,ans=0x3f3f3f3f;
int get(int x){
    if (!fg[x]){
        return 0x3f3f3f3f;
    }
    return x-f[x]+1;
}
void init(){
    int idx=0;
    for (int i=2;i<=N;i++){
        if (!fg[i]){
            primes[++idx]=f[i]=i;
        }
        for (int j=1;j<=idx && primes[j]*i<=N;j++){
            fg[primes[j]*i]=true;
            f[i*primes[j]]=std::max(primes[j],f[i]);
            if (i%primes[j]==0){
                break;
            }
        }
    }
}
signed main(){
    std::cin>>n;
    init();
    for (int i=get(n);i<=n;i++){
        ans=std::min(ans,get(i));
        std::cout<<i<<' '<<ans<<'\n';
    }
    if (ans==0x3f3f3f3f){
        std::cout<<-1;
    }
    else{
        std::cout<<ans;
    }
    return 0;
}