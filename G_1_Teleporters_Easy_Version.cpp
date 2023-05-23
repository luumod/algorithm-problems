#include <bits/stdc++.h>

struct Node{
    int a,b;
};
void solve(){
    int n,c;
    std::cin>>n>>c;
    std::vector<Node> nums; 
    for (int i=1;i<=n;i++){
        int pc;
        std::cin>>pc;
        nums.push_back(Node{i,pc});
    }
    std::sort(nums.begin(),nums.end(),[&](Node& a,Node& b){
        return a.a+a.b<b.a+b.b;
    });
    int p=0;
    for (int i=0;i<nums.size();i++){
        if (c>=nums[i].a+nums[i].b){
            p++;
            c-=nums[i].a+nums[i].b;
        }
    }
    std::cout<<p<<'\n';
}
int main(){
    int n;
    std::cin>>n;
    while (n--){
        solve();
    }
	return 0;
}