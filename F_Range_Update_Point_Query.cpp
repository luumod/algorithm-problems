#include <bits/stdc++.h>

int n,m;
const int N=3e5+10;
int tree[N];
inline int lowbit(int i){
    return i&-i;
}
void update(int i,int c){
    while (i<=n){
        tree[i]+=c;
        i+=lowbit(i);
    }   
}
int query(int i){
    int ans=0;
    while (i){
        ans+=tree[i];
        i-=lowbit(i);
    }
    return ans;
}
int change(int num){
    int ans=0;
    while (num){
        ans+=num%10;
        num/=10;
    }
    return ans;
}
void solve(){
    std::cin>>n>>m;
    std::vector<int> nums(n+1,0);
    for (int i=1;i<=n;i++){
        std::cin>>nums[i];
    }
    for (int i=1;i<=n;i++){
        tree[i]=0;
    }
    while (m--){
        int p,l,r,x;
        std::cin>>p;
        if (p==1){
            std::cin>>l>>r;
            //统计[l,r]中改变的次数
            update(l,1);
            update(r+1,-1);  //利用树状数组维护差分数组
        }
        else if (p==2){
            std::cin>>x;
            //根据改变的次数模拟变化
            int ans=nums[x]; //原始数字
            int cnt=query(x); //查询它被修改了多少次
            //while (cnt>0 && ans>=10){
            for (int i=1;i<=cnt;i++){
                if (ans<10) break;
                ans=change(ans);
            }
            std::cout<<ans<<'\n';
        }
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