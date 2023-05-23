#include <bits/stdc++.h>

std::string a;
int b;
std::vector<int> A;
std::deque<int> ans;
//大数除以小数
void big_div(){
    long long cur=0;
    std::reverse(A.begin(),A.end());
    //除法进行时高位在前
    for (int i=0;i<A.size();i++){
        cur=cur*10+A[i];
        ans.push_back(cur/b); //存商
        cur%=b; //更新余数
    }
    //转换为
    while (ans.size()>1 && !ans.front()){
        ans.pop_front();
    }
}
int main(){
    std::cin>>a>>b;
    for (int i=a.size()-1;i>=0;i--){
        A.push_back(a[i]-'0');
    }
    big_div();
    for (auto& x:ans){
        std::cout<<x;
    }
	return 0;
}