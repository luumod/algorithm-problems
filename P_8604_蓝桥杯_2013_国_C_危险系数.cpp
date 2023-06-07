#include<bits/stdc++.h>
#if 0
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=1e3+10,M=1e5+10;
std::vector<int> vec[N];
int n,m,ans,vis[N];
int u,v,del;
bool bfs(){
    memset(vis,0,sizeof(vis));
    std::queue<int> q;
    q.push(u);
    while (!q.empty()){
        auto p=q.front();
        q.pop();
        if (p==v){
            return true; //可以到达v点
        }
        vis[p]=true;
        for (auto& x:vec[p]){
            if (del!=x && !vis[x]){
                q.push(x);
            }
        }
    }
    return false;
}
signed main(){
    std::cin>>n>>m;
    for (int i=1;i<=m;i++){
        std::cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    std::cin>>u>>v;
    if (!bfs()){
        std::cout<<-1;
        return 0;
    }
    for (int i=1;i<=n;i++){
        if (i!=u && i!=v){
            del=i;
            if (!bfs()){
                ans++;
            }
        }
    }
    std::cout<<ans;
    return 0;
}