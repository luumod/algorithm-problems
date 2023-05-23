#include <bits/stdc++.h>

const int mod=998244353;
int main(){
    int n,m,a,b;
    std::cin>>n>>m>>a>>b;
    std::vector<std::vector<int>> arr(n,std::vector<int>(m,0));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            std::cin>>arr[i][j];
        }
    }
    std::vector<std::vector<int>> numsRowMin(n,std::vector<int>(m,0)),numsRowMax(n,std::vector<int>(m,0));
    std::vector<std::vector<int>> numsColMin(n,std::vector<int>(m,0)),numsColMax(n,std::vector<int>(m,0));
    std::function<void(int)> getRowMin=[&](int i){
        //维护行的最小值,窗口长度为b
        std::deque<int> deq;
        for (int j=0;j<m;j++){
            while (!deq.empty() && deq.front()<j-b+1){
                deq.pop_front();
            }
            while (!deq.empty() && arr[i][j]<=arr[i][deq.back()]){
                deq.pop_back();
            }
            deq.push_back(j);
            if (j>=b-1){
                numsRowMin[i][j]=arr[i][deq.front()];
            }
        }
    };
    std::function<void(int)> getRowMax=[&](int i){
        //维护行的最大值,窗口长度为b
        std::deque<int> deq;
        for (int j=0;j<m;j++){
            while (!deq.empty() && deq.front()<j-b+1){
                    deq.pop_front();
            }
            while (!deq.empty() && arr[i][j]>=arr[i][deq.back()]){
                    deq.pop_back();
            }
            deq.push_back(j);
            if (j>=b-1){
                numsRowMax[i][j]=arr[i][deq.front()];
            }
        }
    };
    std::function<void(int)> getColMax=[&](int j){
        //在行的基础上维护列的最大值,窗口长度为a
        std::deque<int> deq;
        for (int i=0;i<n;i++){
            while (!deq.empty() && deq.front()<i-a+1){
                    deq.pop_front();
            }
            while (!deq.empty() && numsRowMax[i][j]>=numsRowMax[deq.back()][j]){
                    deq.pop_back();
            }
            deq.push_back(i);
            if (i>=a-1){
                numsColMax[i][j]=numsRowMax[deq.front()][j];
            }
        }
    };
    std::function<void(int)> getColMin=[&](int j){
        //在行的基础上维护列的最小值,窗口长度为a
        std::deque<int> deq;
        for (int i=0;i<n;i++){
            while (!deq.empty() && deq.front()<i-a+1){
                    deq.pop_front();
            }
            while (!deq.empty() && numsRowMin[i][j]<=numsRowMin[deq.back()][j]){
                    deq.pop_back();
            }
            deq.push_back(i);
            if (i>=a-1){
                numsColMin[i][j]=numsRowMin[deq.front()][j];
            }
        }
    };
    for (int i=0;i<n;i++){
        getRowMin(i);
        getRowMax(i);
    }
    for (int j=0;j<m;j++){
        getColMin(j);
        getColMax(j);
    }
#if 0
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            std::cout<<numsColMax[i][j]<<' ';
        }
        putchar('\n');
    }
    putchar('\n');
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            std::cout<<numsRowMin[i][j]<<' ';
        }
        putchar('\n');
    }
#endif
    long long ans=0;
    for (int i=a-1;i<n;i++){
        for (int j=b-1;j<m;j++){
            ans+=(numsColMax[i][j]*numsColMin[i][j])%mod;
        }
    }
    std::cout<<ans;
	return 0;
}