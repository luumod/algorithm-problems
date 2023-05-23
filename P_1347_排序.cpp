#include <bits/stdc++.h>

const int N=30;
std::vector<int> vec[N];
int din[N],tdin[N];
int n,m;
std::unordered_set<int> ust;
void topoSort(int i){
    memcpy(tdin,din,sizeof(din));
    std::queue<std::pair<int,int>> q;
    int sum=0; //判断环
    for (int i=1;i<=n;i++){
        //当前点必须出现过，并且入度为0才能加入队列
        if (!tdin[i] && ust.count(i)){       
            q.push({i,1});
            sum++;
        }
    }
    int mx=0; //注意mx是寻找答案的关键：记录当前在第几层，如果层数等于n则说明找到了答案
    std::string s;
    while (!q.empty()){
        auto p=q.front();
        q.pop();
        s+=(p.first+'A'-1);
        for (auto& x:vec[p.first]){
            tdin[x]--;
            if (!tdin[x]){
                q.push({x,p.second+1}); //入度为0，则入队列
                sum++;
                //每次更新层数
                mx=std::max(mx,p.second+1);
            }
        }
    }
    //如果这里写s.size()==n是不可以的。
    if (mx==n){ //全部元素都找到了
        std::cout<<"Sorted sequence determined after "<<i<<" relations: "<<s<<".\n";
        exit(0);
    }
    else if (sum!=(int)ust.size()){
        std::cout<<"Inconsistency found after "<<i<<" relations.\n";
        exit(0);
    }
}
int main(){
    std::cin>>n>>m;
    for (int i=1;i<=m;i++){
        std::string s;
        std::cin>>s;
        int x=s[0]-'A'+1,y=s[2]-'A'+1;
        vec[x].push_back(y);
        ust.insert(x),ust.insert(y);
        din[y]++;
        //每次都进行一次拓朴排序，直到确定关系为止
        topoSort(i);
    }
    std::cout<<"Sorted sequence cannot be determined.\n";
	return 0;
}