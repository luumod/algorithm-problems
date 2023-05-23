#include <bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;
    std::vector<int> vec(2*n+1);
    for (int i=1;i<=n;i++){
        std::cin>>vec[i];
        vec[i+n]=vec[i];
    }
    int i=1,j=2;
    auto f=[&](){
            //寻找循环同构串中的字典序最小的一串
        while (i<=n && j<=n){
            int k=0;
            for (k=0;k<n && vec[i+k]==vec[j+k];k++);
            if (vec[i+k]>vec[j+k]){
                i=i+k+1;
            }
            else{
                j=j+k+1;
            }
            if (i==j){
                j++;
            }
        }
    };
    f();
    for (int s=std::min(i,j),len=1;len<=n;s++,len++){
        std::cout<<vec[s]<<' ';
    }
	return 0;
}