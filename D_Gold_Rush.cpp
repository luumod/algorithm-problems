#include <bits/stdc++.h>

void solve(){
    int n,m;
    std::cin>>n>>m;
    if (n==m){
        std::cout<<"YES\n";
        return;
    }
    if (m>n){
        std::cout<<"NO\n";
        return;
    }
    std::vector<int> vec{n};
    auto f=[&](){
        for (auto& x:vec){
            if (x!=1){
                return true;
            }
        }
        return false;
    };
    while (f()){
        std::vector<int> t;
        int temp=n;
        for (auto& x:vec){
            int n1=x/3*2,n2=x/3;
            if (n1+n2!=x){
                continue;
            }
            if (n1==m || n2==m){
                std::cout<<"YES\n";
                return;
            }
            t.push_back(n1);
            t.push_back(n2);
        }
        vec=t;
    }
    std::cout<<"NO\n";
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}