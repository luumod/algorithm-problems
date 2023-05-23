#include <bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;
    int ans=0;
    int cnt[5]{};
    for (int i=0;i<n;i++){
        int num;
        std::cin>>num;
        cnt[num]++;
    }
    ans+=cnt[4];
    ans+=cnt[2]/2;
    //如果有5个2，则会多出来一个2
    if (cnt[2]&1){
        ans++;
        if (cnt[1]>=2){
            cnt[1]-=2; //1 1 2
        }
        else if (cnt[1]>=1){
            cnt[1]--;  //1 2
        }
    }
    //1 3
    if (cnt[1]==cnt[3]){
        ans+=cnt[1]; // 1 1 3 3 ==> 2
    }
    else if (cnt[1]>cnt[3]){ // 1 1 1 3
        ans+=cnt[3]; //+1
        cnt[1]-=cnt[3]; // 1 1
        ans+=cnt[1]/4; 
        if (cnt[1]%4){
            ans++;   // 1 1  ==> +2
        }
    }
    else if (cnt[1]<cnt[3]){ // 1 3 3 3
        ans+=cnt[3];  // +3
    }
    std::cout<<ans;
	return 0;
}