#include <bits/stdc++.h>

typedef long long ll;
void solve(){
    ll num;
    std::cin>>num;
    int ans=0;
    while (num%6==0){
        ans++;
        num/=6;
    }   
    while (num%3==0){
        ans+=2;
        num/=3;
    }
    if (num==1){
        std::cout<<ans<<'\n';
    }
    else{
        std::cout<<-1<<'\n';
    }
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}