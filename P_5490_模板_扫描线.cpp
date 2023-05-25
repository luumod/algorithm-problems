#include<bits/stdc++.h>
#if 0
    #define int long long
#endif
using ll=long long;
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=1e5+10;
int n;
int Y[N*4];
ll ans;
struct Line{
    int x,y1,y2,fg; //第i条扫描线的x位置，最低点：y1，最高点：y2，fg表示当前扫描线的标记
    bool operator<(Line& p){
        return x<p.x;
    }
}line[N*4];
struct Tree{
    int l,r,len,cnt; //左右边界，实际区间长度，区间覆盖次数
}tree[N*32];
void push_up(int i){
    if (tree[i].cnt){
        tree[i].len=tree[i].r-tree[i].l;
    }
    else{
        tree[i].len=tree[i<<1].len+tree[i<<1|1].len; //需要开32倍空间防止越界
    }
}
void build(int i,int pl,int pr){
    //创建离散线段树
    tree[i].l=Y[pl],tree[i].r=Y[pr]; //当前实际长度
    if (pr==pl+1){
        //叶子节点的宽度为2： [1,2][2,3]...
        return;
    }
    int mid=pl+pr>>1;
    build(i<<1,pl,mid);
    build(i<<1|1,mid,pr);
}
void change(int i,int pl,int pr,int c){
    if (pl>=tree[i].r || pr<=tree[i].l){//越界
        return;
    }
    if (pl<=tree[i].l && tree[i].r<=pr){
        tree[i].cnt+=c;
        push_up(i);
        return;
    }
    change(i<<1,pl,pr,c);
    change(i<<1|1,pl,pr,c);    
    push_up(i);
}   
signed main(){
    std::cin>>n;
    for (int i=1;i<=n;i++){
        int x1,y1,x2,y2;
        std::cin>>x1>>y1>>x2>>y2;
        line[i]={x1,y1,y2,1},line[i+n]={x2,y1,y2,-1}; //对应的两条线 +1 -1
        Y[i]=y1,Y[i+n]=y2; //低值和高值
    }
    n*=2; //扫描线的个数为 2*n 实际需要枚举 2n-1条
    std::sort(line+1,line+1+n); //扫描线从左往右排序
    std::sort(Y+1,Y+1+n);  //Y值离散化
    build(1,1,n);
    for (int i=1;i<n;i++){
        change(1,line[i].y1,line[i].y2,line[i].fg);
        ans+=1ll*(line[i+1].x-line[i].x)*tree[1].len;
    }
    std::cout<<ans;
    return 0;
}