#include <bits/stdc++.h>

int main(){
    int n,m;
    std::cin>>n>>m;
    std::vector<int> vec(n+1);
    for (int i=1;i<=n;i++){
        std::cin>>vec[i];
    }
    std::sort(vec.begin()+1,vec.begin()+1+n);
    int ans=0;
    for (int i=1;i<=m;i++){
        if (vec[i]>0){
            continue;
        }
        ans+=abs(vec[i]);
    }
    std::cout<<ans;
	return 0;
}