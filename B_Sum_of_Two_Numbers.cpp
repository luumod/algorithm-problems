#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int>ans;
int dig(int n)
{
    int res=0;
    while(n){
        res+=n%10,n/=10;
    }
    return res;
}
signed main()
{
	int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        if(ans[n]){
            cout<<ans[n]<<' '<<n-ans[n]<<'\n';
        }
        else
        {
            int x=n/2,y=n-x;
            while(abs(dig(x)-dig(y))>1){
                x++,y--;
            }
            ans[n]=x;
            cout<<x<<' '<<y<<'\n';
        }
    }
}