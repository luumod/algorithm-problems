#include <bits/stdc++.h>
typedef long long ll;

const int N=150000;
std::vector<ll> nums; //存质数
void init(bool ffg){
    std::vector<bool> fg(N+10,false);
    if (ffg){
        for (int i=2;i<=N;i++){
            if (!fg[i]){
                nums.push_back(i);
                if ((ll)i*i<=N){
                    for (int j=i*i;j<=N;j+=i){
                        fg[j]=true;
                    }
                }
            }
        }
    }
    else{
        //线氏筛
        for (int i=2;i<=N;i++){
            if (!fg[i]){
                nums.push_back(i);
            }
            for (int j=0;j<nums.size() && i*nums[j]<=N;j++){
                fg[i*nums[j]]=true;
                if (i%nums[j]==0){
                    break;
                }
            }
        }
    }
}
int main(){
    init(false);
    int n;
    while (std::cin>>n){
        std::cout<<nums[n-1]<<'\n';
    }
	return 0;
}