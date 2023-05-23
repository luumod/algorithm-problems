#include <bits/stdc++.h>

void solve(){
    int n;
    std::string s;
    std::cin>>n>>s;
    int i,j;
    for (i=0,j=n-1;i<j;i++,j--){
        if (s[i]==s[j]){
            break;
        }
    }
    std::cout<<j-i+1<<'\n';
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}