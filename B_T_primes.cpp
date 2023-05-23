#include <bits/stdc++.h>
#define int long long 
const int N=1e6+10;
std::unordered_set<int> primes;
void init(){
    std::vector<bool> vis(N+1);
    for (int i=2;i<=N;i++){
        if (!vis[i]){
            primes.insert(i);
            if ((long long)i*i<=N){
                for (int j=i*i;j<=N;j+=i){
                    vis[j]=true;
                }
            }
        }
    }
}
signed main(){
    init(); //筛质数
    int n;
    std::cin>>n;
    std::vector<int> vec;
    while (n--){
        int num;
        std::cin>>num;
        vec.push_back(num);
    }

    /*
    判断是否恰好有3个因子
    4: 1 2 4 是
    9: 1 3 9 是
    16:1 2 4 8 16 不是
    如果一个数字的sqrt的平方为其本身，则是满足题意的部分数字
    如果sqrt是质数则说明是T质数，比如16的sqrt为4，但是4是个合数，因此不是T质数
    */
    for (auto& x:vec){
        int sq=sqrt(x);
        if (sq*sq!=x){
            std::cout<<"NO\n";
        }
        else{
            if (primes.count(sq)){
                std::cout<<"YES\n";
            }
            else{
                std::cout<<"NO\n";
            }
        }
    }
	return 0;
}