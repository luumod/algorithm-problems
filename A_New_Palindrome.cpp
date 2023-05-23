#include <bits/stdc++.h>

void solve(){
    std::string s;
    std::cin>>s;
    int n=s.size();
    for (int i=0;i<n/2-1;i++){
        std::string d=s;
        std::swap(d[i],d[i+1]);
        std::swap(d[n-i-1],d[n-i-2]);
        if (d!=s){
            std::cout<<"YES\n";
            return;
        }
    }
    std::cout<<"NO\n";
}
int main(){
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
    return 0;
}