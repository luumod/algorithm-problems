#include <bits/stdc++.h>

std::string a,b;
std::vector<int> A,B,ans;
bool comp(){
    if (a.size()!=b.size()){
        return a.size()<b.size(); //true 交换
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
    //高位在前，低位在后
    std::reverse(ans.begin(),ans.end());
}
int main(){
    std::cin>>a>>b;
    //转换为低位在前，高位在后，方便计算
    for (int i=a.size()-1;~i;i--){
        A.push_back(a[i]-'0');
    }
    for (int i=b.size()-1;~i;i--){
        B.push_back(b[i]-'0');
    }
    //规定始终是大数减小数，如果A是一个小数，则我们交换。然后输出一个 '-'
    if (comp()){
        std::swap(A,B);
        std::cout<<"-";
    }
    big_minus();
    for (auto& x:ans){
        std::cout<<x;
    }
	return 0;
}