#include <bits/stdc++.h>
using ll=long long;
int main(){
    int n,m;
    std::cin>>n>>m;
    std::vector<ll> stu(n+1),b(n+5),sum(n+5),d(m+1),s(m+1),t(m+1);
    for (int i=1;i<=n;i++){
        std::cin>>stu[i];
    }
    /*
    从0号订单开始，每次累加[s,t]范围内d值，直到某值大于stu[i]，则表示无法满足，返回false；否则返回true，表示全部都满足
    */
    auto check=[&](int mid){
        std::fill(sum.begin(),sum.end(),0);
        std::fill(b.begin(),b.end(),0);
        for (int i=1;i<=mid;i++){//对m个订单
            //差分操作
            b[s[i]]+=d[i];
            b[t[i]+1]-=d[i];
        }
        //计算前缀和
        for (int i=1;i<=n;i++){//对于所有的教室
            sum[i]=sum[i-1]+b[i];
            if (sum[i]>stu[i]){ //借的超过总的，无法满足
                return false;
            }
        }
        return true; //可以满足
    };
    for (int i=1;i<=m;i++){
        std::cin>>d[i]>>s[i]>>t[i];
    }
    //二分可以满足前多少个订单
    int l=0,r=m+1;
    while (l+1<r){
        int mid=l+r>>1;
        if (check(mid)){
            l=mid; //寻找最大值
        } 
        else{
            r=mid;
        }
    }
    if (l==m){ 
        std::cout<<0;
    }
    else{
        std::cout<<-1<<'\n'<<l+1;
    }
	return 0;
}