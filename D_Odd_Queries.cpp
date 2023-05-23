#include <bits/stdc++.h>

int main(){
    int t;
    std::cin>>t;
    while (t--){
        int n,q;
        std::cin>>n>>q;
        std::vector<int> nums(n+1,0);
        int sum = 0;
        for (int i=1;i<=n;i++){
            scanf("%d",&nums[i]);
            nums[i]+=nums[i-1];
        }
        sum = nums[n];
        for (int i=1;i<=q;i++){
            int ol = sum;
            int l,r,pn;
            scanf("%d%d%d",&l,&r,&pn);
            sum -= nums[r] - nums[l-1];
            sum += (r-l+1)*pn;
            if (sum%2==0){
                puts("NO");
            }
            else{
                puts("YES");
            }
            sum = ol; 
        }
    }
	return 0;
}