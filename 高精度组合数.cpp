#include<bits/stdc++.h>
#if 1
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=1e5+10;
int n,m;
int primes[N],C[N];
int cnt=0;
void init(){
    //预处理[1,n]中有多少质数
    std::vector<int> fg(n,false);
    for (int i=2;i<=n;i++){
        if (!fg[i]){
            primes[++cnt]=i;
        }
        for (int j=1;1ll*i*primes[j]<=n;j++){
            fg[i*primes[j]]=true;
            if (i%primes[j]==0){
                break;
            }
        }
    }
}
int get(int n,int p){
    //n!有多少p质数
    int cnt=0;
    while (n){
        cnt+=n/p;
        n/=p;
    }
    return cnt;
}
int how(int n,int m,int p){
    return get(n,p)-get(n-m,p)-get(m,p);
}
void mul(int s,int& len){
    //高精度乘法
    int t=0;
    for(int i=0;i<len;i++){
        t+=C[i]*s;
        C[i]=t%10;
        t/=10;
    }
    while (t){
        C[len++]=t%10;
        t/=10;
    }
}
signed main(){
    //求C(n,m)
    std::cin>>n>>m; 
    init();
    int len=1;
    C[0]=1;
    for (int i=1;i<=cnt;i++){
        int x=primes[i];
        int s=how(n,m,x); //C[i]中有多少质数x
        while (s--){
            mul(x,len);
        }
    }
    for (int i=0;i<len;i++){
        std::cout<<C[len-i-1];
    }
    return 0;
}