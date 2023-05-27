#include<bits/stdc++.h>
#if 0
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=1e3+10,M=1e4+10;
int n,m,a[N];
int dis[N],vis[N];
struct Node{
    int to,w,next;
}edge[M<<2];
int head[N],cnt;
void add_edge(int u,int v,int w){
    edge[++cnt]={v,w,head[u]};
    head[u]=cnt;
}
void spfa(int s){
    memset(dis,0x3f,sizeof(dis));
    std::queue<int> q;
    q.push(s);
    dis[s]=0;
    vis[s]=true;
    while (!q.empty()){
        auto u=q.front();
        q.pop();
        vis[u]=false;
        for (int i=head[u];i;i=edge[i].next){
            int v=edge[i].to,w=edge[i].w;
            if (v==n){
                if (dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                    if (!vis[v]){
                        q.push(v);
                        vis[v]=true;
                    }
                }
            }
            else if (dis[v]>dis[u]+w+a[v]){
                dis[v]=dis[u]+w+a[v];
                if (!vis[v]){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
}   
signed main(){
    std::cin>>n>>m;
    for (int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    for (int i=1;i<=m;i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    spfa(1);
    std::cout<<dis[n];
    return 0;
}