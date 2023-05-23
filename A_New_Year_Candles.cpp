#include <bits/stdc++.h>

int main(){
    int n,b;
    std::cin>>n>>b;
    int ans=0;
    int cnt=0;
    std::vector<int> vec(n,0);
    while (!vec.empty()){
        vec.pop_back();
        ans+=1;
        cnt++;
        if (cnt%b==0){
            vec.push_back(0);
        }
    }
    std::cout<<ans;
	return 0;
}