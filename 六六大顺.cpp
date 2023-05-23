#include<bits/stdc++.h>
#if 1
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=1e7+10;
int n,b; //b是商 
std::vector<int> A,B,ans;

//高精度+法
void big_add(){
    ans.clear();
    int ne=0;
    for (int i=0;i<A.size() || i<B.size();i++){
        if (i<A.size()){
            ne+=A[i];
        }
        if (i<B.size()){
            ne+=B[i];
        }
        ans.push_back(ne%10);
        ne/=10;
    }
    if (ne){
        ans.push_back(ne%10);
    }
}
bool comp(){
    if (A.size()!=B.size()){
        return A.size()<B.size(); //true 交换
    }
    //sizeA==sizeB
    for (int i=0;i<A.size();i++){
        if (A[i]!=B[i]){
            return A[i]<B[i]; //true
        }
    }
    return false;
}
void big_minus(){
    ans.clear();
    for (int i=0;i<A.size();i++){
        int t=A[i];
        if (i<B.size()){
            t-=B[i];
        }
        if (t<0){ //借位
            t+=10;
            A[i+1]-=1;
        }
        ans.push_back(t);
    }
    while (ans.size()>1 && ans.back()==0){
        ans.pop_back();
    }
}
void big_mul(){
    ans.clear();
    ans.resize(A.size()+B.size());
    for (int i=0;i<A.size();i++){
        for (int j=0;j<B.size();j++){
            ans[i+j]+=A[i]*B[j];
            ans[i+j+1]+=ans[i+j]/10; //进位
            ans[i+j]%=10;  //当前位
        }
    }
    //处理前导0
    while (ans.size()>1 && !ans.back()){
        ans.pop_back();
    }
}
//大数除以小数
void big_div(){
    ans.clear();
    long long cur=0;
    std::reverse(A.begin(),A.end());
    //除法进行时高位在前
    for (int i=0;i<A.size();i++){
        cur=cur*10+A[i];
        ans.push_back(cur/b); //存商
        cur%=b; //更新余数
    }
    std::reverse(ans.begin(),ans.end());
    //转换为
    while (ans.size()>1 && !ans.back()){
        ans.pop_back();
    }
}
signed main(){
    std::cin>>n;
    b=9;
    for (int i=1;i<=n;i++){
        A.push_back(1);
        A.push_back(0);
    }
    A.push_back(0);
    std::reverse(A.begin(),A.end());
    
    B.push_back(0);
    for (int i=1;i<=n;i++){
        B.push_back(2);
    }

    big_minus(); //减法
    A=ans;

    std::vector<int> tn;
    std::string s=std::to_string(n);
    for (int i=s.size()-1;i>=0;i--){
        tn.push_back(s[i]-'0');
    }
    B=tn;
    big_add();  //加法
    A=ans;

    B.clear();
    B.push_back(4);
    big_mul();  //乘法
    A=ans;

    B.clear();
    B.push_back(9);
    big_div();
    
    for (int i=ans.size()-1;i>=0;i--){
        std::cout<<ans[i];
    }
    return 0;
}



