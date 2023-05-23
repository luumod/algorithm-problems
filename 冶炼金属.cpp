#include <bits/stdc++.h>

const int N = 1e4+10;
int n;
int A[N],B[N];
int mx = 0;
int mi = 1e9+10;
void solve(){
    for (int i=1;i<=n;i++){
        int l=A[i]/(B[i]+1)+1,r=A[i]/B[i];
        mx = std::max(mx,l);
        mi = std::min(mi,r);
    }   
    std::cout<<mx<<' '<<mi;
}
int main(){
    std::cin>>n;
    for (int i=1;i<=n;i++){
        std::cin>>A[i]>>B[i];
    }
    solve();
	return 0;
}