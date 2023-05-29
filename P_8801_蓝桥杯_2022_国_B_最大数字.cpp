#include<bits/stdc++.h>
#if 0
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=1e3+10;
std::string s,ans;
int A,B,n;
/*
1. 如果可以变为9，则判断那种方式更优，则用那种
2. 如果不可以变为9，则尽量add操作
*/
void dfs(int i,int add,int mis,std::string str){
    if (i==n){
        //取得最大值
        ans=std::max(ans,str);
        return;
    }
    int addNum='9'-str[i],misNum=str[i]-'0'+1; //加操作和减操作到达9需要的次数
    if (addNum+add<=A && misNum+mis<=B){
        str[i]='9';
        dfs(i+1,add+addNum,mis,str);
        dfs(i+1,add,mis+misNum,str);
    }
    else if (addNum+add<=A){ //只能进行操作1: add
        str[i]='9';
        dfs(i+1,add+addNum,mis,str);
    }
    else if (misNum+mis<=B){ //只能进行操作2: mis 
        str[i]='9';
        dfs(i+1,add,mis+misNum,str);
    }
    else{ //两种操作无法到达9，则尽可能的执行add操作
        str[i]+=A-add;
        dfs(i+1,A,mis,str);
    }
}
signed main(){
    std::cin>>s>>A>>B;
    n=s.size();
    dfs(0,0,0,s);
    std::cout<<ans;
    return 0;
}