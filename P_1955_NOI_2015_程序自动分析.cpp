#include<bits/stdc++.h>
#if 0
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=2e6+10;
int n;
int fa[N];
int new_len;
struct Node{
    int x,y,e;
}a[N];
std::vector<int> veca;
void init(){
    for (int i=0;i<=new_len;i++){
        fa[i]=i;
    }
}
int find(int x){
    if (x!=fa[x]){
        return fa[x]=find(fa[x]);
    }
    return x;
}
void solve(){
    std::cin>>n;
    veca.clear();
    memset(a,0,sizeof(a));
    memset(fa,0,sizeof(fa));
    for (int i=1;i<=n;i++){
        std::cin>>a[i].x>>a[i].y>>a[i].e;
        veca.push_back(a[i].x);
        veca.push_back(a[i].y);
    }
    std::sort(veca.begin(),veca.end());
    new_len=std::unique(veca.begin(),veca.end())-veca.begin();
    for (int i=1;i<=n;i++){
        a[i].x=std::lower_bound(veca.begin(),veca.begin()+new_len,a[i].x)-veca.begin();
        a[i].y=std::lower_bound(veca.begin(),veca.begin()+new_len,a[i].y)-veca.begin();
    }
    init();
    std::sort(a+1,a+1+n,[&](const Node& p1,const Node& p2){
        return p1.e>p2.e;
    });
    for (int i=1;i<=n;i++){
        int x=find(a[i].x);
        int y=find(a[i].y);
        if (a[i].e==1){
            fa[x]=y;
        }
        else if (x==y){
            std::cout<<"NO\n";
            return;
        }
    }
    std::cout<<"YES\n";
}
signed main(){
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
    return 0;
}