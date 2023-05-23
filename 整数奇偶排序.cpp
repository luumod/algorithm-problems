#include <bits/stdc++.h>

int main(){
    int n=10;
    std::vector<int> arr(n,0);
    std::priority_queue<int,std::vector<int>> qOdd;
    std::priority_queue<int,std::vector<int>,std::greater<int>> qEven;
    for (int i=0;i<n;i++){
        std::cin>>arr[i];
        if (arr[i]&1){
            qOdd.push(arr[i]);
        }
        else{
            qEven.push(arr[i]);
        }
    }   
    while (!qOdd.empty()){
        std::cout<<qOdd.top()<<' ';
        qOdd.pop();
    }
    while (!qEven.empty()){
        std::cout<<qEven.top()<<' ';
        qEven.pop();
    }
	return 0;
}