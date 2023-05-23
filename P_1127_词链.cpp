#include <bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;
    std::vector<std::string> arr(n+1);
    std::vector<char> beg(n+1),end(n+1);
    for (int i=1;i<=n;i++){
        std::cin>>arr[i];
        beg[arr[i].front()]++;
        end[arr[i].back()]++;
    }   
    std::sort(arr.begin()+1,arr.begin()+1+n);
    char s,e;
    for (int i='a';i<='z';i++){
        char ch=i;
        if (abs(beg[ch]-end[ch])==1){
            if (beg[ch]-end[ch]==1){
                s=ch;
            }
            if (end[ch]-beg[ch]==1){
                e=ch;
            }
        }
    }
    int cnt=end[e];
    int start=0;
    for (int i=1;i<=n;i++){
        if (arr[i].front()==s && (arr[i].back()!=e || cnt!=1)){
            start=i;
            break;
        }
    }
    bool fg=false;
    std::vector<std::string> temp,ans;
    std::vector<bool> vis(n+1);
    std::function<void(int,int)> dfs=[&](int last,int now){
        if (fg){
            return;
        }
        if (now==n){
            fg=true;
            ans=temp;
            return;
        }
        for (int i=1;i<=n;i++){
            if (!vis[i] && arr[last].back()==arr[i].front()){
                vis[i]=true;
                temp.push_back(arr[i]);
                dfs(i,now+1);
                temp.pop_back();
                vis[i]=false;
            }
        }
    };
    vis[start]=true;
    temp.push_back(arr[start]);
    dfs(start,1);
    if (!fg){   
        std::cout<<"***";
    }
    else{
        for (int i=0;i<ans.size();i++){
            std::cout<<ans[i];
            if (i==ans.size()-1){
                break;
            }
            std::cout<<'.';
        }
    }
	return 0;
}