#include <bits/stdc++.h>

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
void solve(){
    int n;
    std::cin>>n;
    std::vector<int> vec(n+1),temp(n+1),s(n+1);
    for (int i=1;i<=n;i++){
        s[i]=i;
        std::cin>>vec[i];
    }
    std::unordered_set<int> ust;
    int k=0;
    for (int i=1;i<=n;i++){
        k=gcd(k,abs(vec[i]-i));
    }
    std::cout<<k<<'\n';
}
int main(){
    int t;
    std::cin>>t;
    while (t--){
        solve();
    }
    return 0;
}