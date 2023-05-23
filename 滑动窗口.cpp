#include <bits/stdc++.h>

int main(){
    int n,k;
    std::cin>>n>>k;
    std::vector<int> arr(n);
    for (int i=0;i<n;i++){
        std::cin>>arr[i];
    } 
    std::deque<int> deq;
    for (int i=0;i<n;i++){
        while (!deq.empty() && deq.front()<i-k+1){
            deq.pop_front();
        }
        while (!deq.empty() && arr[i]<=arr[deq.back()]){
            deq.pop_back();
        }
        deq.push_back(i);
        if (i>=k-1){
            std::cout<<arr[deq.front()]<<' ';
        }
    }
    deq.clear();
    putchar('\n');
    for (int i=0;i<n;i++){
        while (!deq.empty() && deq.front()<i-k+1){
            deq.pop_front();
        }
        while (!deq.empty() && arr[i]>=arr[deq.back()]){
            deq.pop_back();
        }
        deq.push_back(i);
        if (i>=k-1){
            std::cout<<arr[deq.front()]<<' ';
        }
    }
	return 0;
}