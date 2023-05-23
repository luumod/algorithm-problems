#include<bits/stdc++.h>
#if 0
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

const int N=1e3+10;
int limit[N][N],dis[N][N],temp[N][N];
int n,Q;
void floyd(){
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                temp[i][j]=std::min(temp[i][j],temp[i][k]+temp[k][j]);
            }
        }
    }
}
int getSum(){
    int ans=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            ans+=temp[i][j];
        }
    }
    return ans;
}
bool check(int day){
    //治理mid天，看看满足要求吗
    memcpy(temp,dis,sizeof(dis)); //保存原dis
    for (int i =1; i<=n; i++)
	{
		int val = day/n+(day%n>=i?1:0);
		for (int j =1 ; j<=n; j++)
		{
		    temp[i][j]-=val;
		    if (temp[i][j]<limit[i][j]) temp[i][j]=limit[i][j];
		    temp[j][i]-=val;
		    if (temp[j][i]<limit[j][i]) temp[j][i]=limit[j][i];
		}
	}
    floyd();
    return getSum()<=Q; //满足
}
signed main(){
    memset(dis,0x3f,sizeof(dis));
    memset(limit,0x3f,sizeof(limit));
    std::cin>>n>>Q;
    for (int i=1;i<=n;i++){
        dis[i][i]=0;
        for (int j=1;j<=n;j++){
            int x;
            std::cin>>x;
            dis[i][j]=x;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int x;
            std::cin>>x;
            limit[i][j]=x;
        }
    }
    //二分治理多少天： 需要寻找最小值
    int l=-1,r=1e5*n,ans=-1;
    while (l+1<r){
        int mid=l+r>>1;
        if (check(mid)){ //更新寻找最小值
            r=mid;      
            ans=mid;
        }   
        else{
            l=mid;
        }
    }
    std::cout<<ans;
    return 0;
}