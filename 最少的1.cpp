#include<bits/stdc++.h>
#if 1
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=1e6+10;
int n;
struct Edge{
    int to,w,next;
}edge[N];
int head[N],cnt;
int dis[N],vis[N];
int first;
void add_edge(int u,int v,int w){
    edge[++cnt]={v,w,head[u]};
    head[u]=cnt;
}
int get(int num){
    int ans;
    while (num){
        ans+=(num%2==1?1:0);
        num/=2;
    }
    return ans;
}
void spfa(int s){
    memset(dis,0x3f,sizeof(dis));
    std::queue<int> q;
    q.push(s);
    dis[s]=0;
    vis[s]=true;
    while (!q.empty()){
        auto p=q.front();
        q.pop();
        vis[p]=false;
        for (int i=head[p];i;i=edge[i].next){
            int to=edge[i].to,w=edge[i].w;
            if (dis[to]>dis[p]+w){
                dis[to]=dis[p]+w;
                if (!vis[to]){
                    q.push(to);
                    vis[to]=true;
                }
            }
        }
    }
}
signed main(){
    std::cin>>n;
    for (int i=0;i<n;i++){
        add_edge(i,(i+1)%n,1);
        add_edge(i,(i*2)%n,0);
    }
    spfa(0);
    int ans=1e9;
    for (int i=0;i<=n;i++){
        std::cout<<dis[i]<<' ';
    }
    //std::cout<<ans;
    return 0;
}

