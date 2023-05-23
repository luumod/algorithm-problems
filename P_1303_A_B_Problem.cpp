#include <bits/stdc++.h>

std::string n,m;
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
int main(){
    std::cin>>n>>m;
    for (int i=n.size()-1;i>=0;i--){
        A.push_back(n[i]-'0');
    }
    for (int j=m.size()-1;j>=0;j--){
        B.push_back(m[j]-'0');
    }
    ans.resize(A.size()+B.size());
    big_mul();
    for (auto& x:ans){
        std::cout<<x;
    }
	return 0;
}