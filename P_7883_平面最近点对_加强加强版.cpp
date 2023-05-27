#include<bits/stdc++.h>
#if 1
    #define int long long
#endif
using ll=long long;
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=4e5+10;
int n;
struct point{
    double x,y;
}p[N],b[N];
double get_dis(const point& l,const point& r){
    return std::sqrt((l.x-r.x)*(l.x-r.x)+(l.y-r.y)*(l.y-r.y));
}
double solve(int l,int r){
    if (l==r){
        return 1e9;
    }
    if (l+1==r){
        return get_dis(p[l],p[r]);
    }
    int mid=l+r>>1;
    double d=std::min(solve(l,mid),solve(mid+1,r));

    int k=0;
    for (int i=l;i<=r;i++){
        if (fabs(p[i].x-p[mid].x)<d){
            b[++k]=p[i];
        }
    }
    std::sort(b+1,b+1+k,[&](const point& a,const point& b){
        return a.y<b.y;
    });
    for (int i=1;i<k;i++){
        for (int j=i+1;j<=k && b[j].y-b[i].y<d;j++){
            d=std::min(d,get_dis(b[i],b[j]));
        }
    }
    return d;
}
signed main(){
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    std::cin>>n;
    for (int i=1;i<=n;i++){
        scanf("%lf%lf",&p[i].x,&p[i].y);
        //std::cin>>p[i].x>>p[i].y;
    }
    std::sort(p+1,p+1+n,[&](const point& a,const point& b){ 
        if (a.x==b.x) return a.y<b.y;
        return a.x<b.x;
    });
    double ans=solve(1,n);
    printf("%.0lf",ans*ans);
    return 0;
}