#include <bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;
    std::vector<int> vec;
    int x;
    while (std::cin>>x){
        vec.push_back(x);
    }
    std::sort(vec.begin(),vec.end());
    int ans1=0,ans2=0;
    for (int i=0;i<vec.size()-1;i++){
        if (vec[i+1]-vec[i]>1){
            ans1=vec[i]+1;
        }
        else if (vec[i]==vec[i+1]){
            ans2=vec[i];
        }
        if (ans1 && ans2){
            break;
        }
    }
    std::cout<<ans1<<' '<<ans2<<'\n';
    return 0;
}