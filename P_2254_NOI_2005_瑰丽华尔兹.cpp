#include<bits/stdc++.h>
#if 0
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=210;
int n,m,x,y,k,ans;
char map[N][N];
int dp[N][N]; //dp[i][j]表示在(i,j)位置的最大价值
int dx[5]{0,-1,1,0,0},dy[5]{0,0,0,-1,1};
struct Node{
    int pos,dp; //位置和最长距离
};
void get(int x,int y,int L,int time,int d){
    //(x,y)表示起始位置，L表示当前方向最长移动长度，time表示时间长度
    std::deque<Node> deq;
    //注意!!! 这个地方要从(x,y)开始，所有一开始不能把x+=,y+=放在下面，因此要放在for循环的后面
    for (int i=1;i<=L;i++,x+=dx[d],y+=dy[d]){ //朝着方向d一直移动
        if (map[x][y]=='x'){
            deq.clear();
        }
        else{
            //单调队列维护最大值
            if (!deq.empty() && deq.front().pos<i-time){
                deq.pop_front();
            }
            //维护窗口最大值
            while (!deq.empty() && deq.back().dp+i-deq.back().pos<=dp[x][y]){
                deq.pop_back();
            }
            deq.push_back({i,dp[x][y]});
            dp[x][y]=deq.front().dp+i-deq.front().pos;
            ans=std::max(ans,dp[x][y]);
        }
    }
}
signed main(){
    std::cin>>n>>m>>x>>y>>k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m
        ;j++){
            std::cin>>map[i][j];
        }
    }
    memset(dp,-0x3f,sizeof(dp));
    dp[x][y]=0;
    for (int i=1;i<=k;i++){
        int s,t,d;  //时间区间[s,t] d方向 1234 上下左右
        std::cin>>s>>t>>d; 
        int time=t-s+1;
        if (d==1){//上
            for (int i=1;i<=m;i++){
                get(n,i,n,time,d);
            }
        }
        if (d==2){//下
            for (int i=1;i<=m;i++){
                get(1,i,n,time,d);
            }
        }
        if (d==3){//左
            for (int i=1;i<=n;i++){
                get(i,m,m,time,d);
            }
        }
        if (d==4){//右
            for (int i=1;i<=n;i++){
                get(i,1,m,time,d);
            }
        }
    }
    std::cout<<ans;
    return 0;
}