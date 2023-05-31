#include<bits/stdc++.h>
#if 0
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=1e3+10;
int map[N][N],sum[N][N],mx;
int r,c,a,b;
bool check(int mid){
    int tot=0,last=0;
    for (int i=1;i<=r;i++){
        int s=0,cnt=0;
        for (int j=1;j<=c;j++){
            s+=sum[i][j]-sum[last][j];
            if (s>=mid){ //某块必须达到mid
                s=0;
                ++cnt; //某一行中的块数++
            }
        }
        if (cnt>=b){ //满足了一行切割成b块
            ++tot;
            last=i; //切下一行
        }
    }
    return tot>=a; //如果可以切a行，则满足条件，寻找较大的
}
signed main(){
    std::cin>>r>>c>>a>>b;
    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++){
            std::cin>>map[i][j];
            sum[i][j]=sum[i-1][j]+map[i][j];
            mx+=map[i][j];
        }
    }
    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++){
            std::cout<<sum[i][j]<<" \n"[j==c];
        }
    }
    //最优的巧克力最少解：最小值最大
    int l=-1,r=mx+1;
    while (l+1<r){
        int mid=l+r>>1;
        if (check(mid)){  //mid表示某块的碎屑和
            l=mid;
        }
        else{
            r=mid;
        }
    }
    std::cout<<l;
    return 0;
}