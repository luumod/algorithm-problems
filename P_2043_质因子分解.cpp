#include <bits/stdc++.h>

const int N=100010;
int cnt[N];
void fenjie(int n){
    for (int i=2;i*i<=n;i++){
        while (n%i==0){
            cnt[i]++;
            n/=i;
        }
    }
    if (n>1){
        cnt[n]++;
    }
}
void solve(){
    int n;
    std::cin>>n;
    /*
    n=10: 2 3 4 5 6 7 8 9 10
    2: 2++
    3: 3++
    4: 2+=2 
    ...
    */
    for (int i=2;i<=n;i++){
        fenjie(i);
    }
    for (int i=1;i<N;i++){
        if (cnt[i]){
            std::cout<<i<<' '<<cnt[i]<<'\n';
        }
    }
}
int main(){
    solve();
	return 0;
}