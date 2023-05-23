#include <bits/stdc++.h>

std::string a,b;
std::vector<int> A,B,ans;
//高精度+法
void big_add(){
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
    //高位在前，低位在后
    std::reverse(ans.begin(),ans.end());
}
void mainAdd(){
    std::cin>>a>>b;
    //转换为低位在前，高位在后，方便计算
    for (int i=a.size()-1;~i;i--){
        A.push_back(a[i]-'0');
    }
    for (int i=b.size()-1;~i;i--){
        B.push_back(b[i]-'0');
    }
    big_add();
    for (auto& x:ans){
        std::cout<<x;
    }
}