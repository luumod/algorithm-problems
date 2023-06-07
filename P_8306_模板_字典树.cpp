#include<bits/stdc++.h>
#if 0
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=3e6+10;
int tree[N][70],idx,cnt[N];
int getnum(char ch){
    if (ch>='A' && ch<='Z'){
        return ch-'A';
    }
    else if (ch>='a' && ch<='z'){
        return ch-'a'+26;
    }
    else{
        return ch-'0'+52;
    }
}   
void update(std::string s){
    int p=0,len=s.size();
    for (int i=0;i<len;i++){
        int c=getnum(s[i]);
        if (!tree[p][c]){
            tree[p][c]=++idx;
        }
        p=tree[p][c];
        cnt[p]++;
    }
}
int query(std::string t){
    int p=0,len=t.size();
    for (int i=0;i<len;i++){
        int c=getnum(t[i]);
        if (!tree[p][c]){
            return 0;
        }
        p=tree[p][c];
    }
    return cnt[p];
}
void solve(){
    int n,q;
    for (int i=0;i<=idx;i++){
        memset(tree[i],0,sizeof(tree[i]));
    }
    for (int i=0;i<=idx;i++){
        cnt[i]=0;
    }
    idx=0;
    std::cin>>n>>q;
    for (int i=1;i<=n;i++){
        std::string s;
        std::cin>>s; 
        update(s);
    }
    for (int i=1;i<=q;i++){
        std::string t;
        std::cin>>t;
        std::cout<<query(t)<<"\n";
    }
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
    return 0;
}