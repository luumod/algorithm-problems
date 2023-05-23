#include <bits/stdc++.h>

void solve(){
    int n;
    std::string s;
    std::cin>>n>>s;
    int x=0,y=0;
    for (int i=0;i<s.size();i++){
        if (s[i]=='U'){
            x+=1;
        }
        else if (s[i]=='L'){
            y-=1;
        }
        else if (s[i]=='R'){
            y+=1;
        }
        else{
            x-=1;
        }
        if (x==1 && y==1){
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