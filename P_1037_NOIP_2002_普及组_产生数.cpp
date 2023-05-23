#include <bits/stdc++.h>
#if 1
    #define int long long
#endif
using ll=long long;

const int N=1e5+10;
int n,m,k;
std::string s;
std::pair<int,int> vec[N];
std::string s1;
int vis[N];
int dfs(char now){
    int ans=1;
    vis[now]=true;
    for (int i=1;i<=k;i++){
        if (vec[i].first==now && !vis[vec[i].second]){
            int nums=dfs(vec[i].second);
            ans+=nums;
        }
    }
    return ans;
}

//高精度*法
std::vector<int> A,B,ans;
void big_mul(){
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
    std::reverse(ans.begin(),ans.end());
}
void mainMul(std::string nn,std::string mm){
    for (int i=nn.size()-1;i>=0;i--){
        A.push_back(nn[i]-'0');
    }
    for (int j=mm.size()-1;j>=0;j--){
        B.push_back(mm[j]-'0');
    }
    ans.resize(A.size()+B.size());
    big_mul();

    s1.clear();
    for (auto& x:ans){
        s1+=x+'0';
    }

    ans.clear();
    A.clear();
    B.clear();
}

signed main(){
    std::cin>>s>>k;
    for (int i=1;i<=k;i++){
        std::cin>>vec[i].first>>vec[i].second;
    }
    s1="1";
    for (auto& x:s){
        memset(vis,0,sizeof(vis));
        int nums=dfs(x-'0');
        auto s2=std::to_string(nums);
        mainMul(s1,s2);
    }
    std::cout<<s1;
    return 0;
}