#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> vec(n+1);
    for (int i=1;i<=n;i++){
        std::cin>>vec[i];
    }
    int cnt=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int z=1;z<=n;z++){
                if (vec[i]+vec[j]==vec[z]){
                    cnt++;
                }
            }
        }        
    }
    std::cout<<cnt<<'\n';
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
    
	return 0;
}