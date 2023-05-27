#include<bits/stdc++.h>
#if 0
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=200010;
int n;
struct point{
    double x,y;
}A[N],B[N],T[N];
double get_dis(const point& a,const point& b){
    return std::sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double solve(int l,int r){
    //分治
    if (l==r){   //只有一个点
        return 1e9;
    }
    if (l+1==r){ //有两个点则算距离
        return get_dis(A[l],A[r]);
    }
    int mid=l+r>>1;
    double d=std::min(solve(l,mid),solve(mid+1,r)); 

    //跨中线处理
    int k=0;
    for (int i=l;i<=r;i++){
        if (fabs(A[i].x-A[mid].x)<d){
            B[++k]=A[i];
        }
    }
    //按照y值排序
    std::sort(B+1,B+1+k,[&](const point& a,const point& b){
        return a.y<b.y;
    });
    for (int i=1;i<k;i++){
        //枚举两个点进行距离的更新
        for (int j=i+1;j<=k && B[j].y-B[i].y<d;j++){
            d=std::min(d,get_dis(B[i],B[j]));
        }
    }
    return d;
}
signed main(){
    std::cin>>n;
    for (int i=1;i<=n;i++){
        std::cin>>A[i].x>>A[i].y;
    }
    //1. 按照x为第一关键字，y为第二关键字排序
    std::sort(A+1,A+1+n,[&](const point& a,const point& b){
        if (a.x==b.x) return a.y<b.y;
        return a.x<b.x;
    });
    printf("%.4lf\n",solve(1,n));
    return 0;
}