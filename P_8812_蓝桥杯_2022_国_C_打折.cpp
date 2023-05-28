#include<bits/stdc++.h>
#if 0
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}


const int N=1e5+10;
int n,m;
int s[N],t[N],p[N],c[N],a[N],val[N],b[N];
std::unordered_map<int,int> ucheap,ori;
std::unordered_set<int> shop;
signed main(){
    std::cin>>n>>m;
    for (int i=1;i<=m;i++){
        std::cin>>s[i]>>t[i]>>p[i]>>c[i];
        for (int j=1;j<=c[i];j++){
            //输入商品
            std::cin>>a[j]>>b[j]; //第a[i]个商品的类型和原价b[i]
            shop.insert(a[j]); //该商店存在第a[j]件商品
            ucheap[a[j]]=std::min(b[j],b[j]*p[i]/100); //获取第1，2，3...n个商品的最低价格
            ori[a[j]]=b[j]; //未打折之前的原价
        }
    }
    int ans=0;
    for (int k=1;k<=m;k++){
        //第s[k]-t[k]天内打折
        for (int i=s[k];i<=t[k];i++){
            //枚举打折的每一天: 在某商店内的打折天数内的第i天打折
            int now=0;
            //遍历所有商店
            for (int p=1;p<=m;p++){
                if (a[p]<=i && i<=t[p]){
                    //遍历所有物品
                    for (int q=1;q<=n;q++){//所有的商品
                        if (shop.count(q)){

                        }
                    }
                }
            }
        }
    }
    
    return 0;
}