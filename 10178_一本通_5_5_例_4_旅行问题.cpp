#include<bits/stdc++.h>
#if 1
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=1e6+10;
int n;
int oil[N],dis[N];
int sum[N<<2],fg[N<<2]; //sum[i]表示从i点出发顺时针或者逆时针到达各个点的剩余油量
std::deque<int> deq;
signed main(){
    std::cin>>n;
    for (int i=1;i<=n;i++){
        std::cin>>oil[i]>>dis[i];
    }

    //顺时针
    for (int i=1;i<=n;i++){
        sum[i]=sum[i+n]=oil[i]-dis[i];
    }
    for (int i=1;i<=n*2;i++){
        sum[i]+=sum[i-1];
    }
    //窗口往左滑动
    for (int i=n*2;i>=1;i--){
        if (!deq.empty() && deq.front()>i+n-1){
            deq.pop_front();
        }
        //维护最小的sum[j],如果sum[j]-sum[i-1]=0则满足i点可以绕一圈
        while (!deq.empty() && sum[deq.back()]>=sum[i]){
            deq.pop_back();
        }
        deq.push_back(i);
        if (i<=n && sum[deq.front()]-sum[i-1]>=0){
            fg[i]=true;
        }
    }
    
    memset(sum,0,sizeof(sum));
    deq.clear();
    //逆时针
    dis[0]=dis[n];
    for (int i=n;i>=1;i--){
        sum[i]=sum[i+n]=oil[i]-dis[i-1];
    }
    for (int i=n*2;i>=1;i--){
        sum[i]+=sum[i+1];
    }
    //窗口往右边滑动
    for (int i=1;i<=n*2;i++){
        if (!deq.empty() && deq.front()<i-n+1){
            deq.pop_front();
        }
        while (!deq.empty() && sum[deq.back()]>=sum[i]){
            deq.pop_back();
        }
        deq.push_back(i);
        if (i>=n+1 && sum[deq.front()]-sum[i+1]>=0){
            //注意此时的序号为i-n
            fg[i-n]=true;
        }
    }
    for (int i=1;i<=n;i++){
        if (fg[i]){
            std::cout<<"TAK\n";
        }
        else{
            std::cout<<"NIE\n";
        }
    }
    return 0;
}