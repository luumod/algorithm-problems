#include <bits/stdc++.h>

void solve(){
    int n,k; //k || k+1
    std::cin>>n>>k;
    std::string s,t;
    std::cin>>s>>t;
    std::unordered_map<char,int> ump;
    for (int i=0;i<n;i++){
        if (i-k<0 && i+k>=n){
            //不能任意移动的位置
            if (s[i]!=t[i]){
                std::cout<<"NO\n";
                return;
            }
        }
        else{
            //可以任意移动往右往左
            ump[s[i]]++;
            ump[t[i]]--;
        }
    }
    for (auto &x:ump){
        if (x.second!=0){
            std::cout<<"NO\n";
            return;
        }
    }
    std::cout<<"YES\n";
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}