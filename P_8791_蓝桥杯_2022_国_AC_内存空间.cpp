#include<bits/stdc++.h>
#if 1
    #define int long long
#endif
template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::pair<T1,T2>pa){out<<"{fi: "<<pa.first<<", se: "<<pa.second<<"}\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::vector<T>vec){for(auto&x:vec){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::deque<T>deq){for(auto&x:deq){out<<x<<' ';}out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::queue<T>q){std::queue<T>t=q;while(!q.empty()){out<<q.front()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename pred>std::ostream&operator<<(std::ostream&out,std::priority_queue<T1,std::vector<T1>,pred>q){auto t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T>std::ostream&operator<<(std::ostream&out,std::stack<T>q){std::stack<T>t=q;while(!q.empty()){out<<q.top()<<" ";q.pop();}q=t;out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::unordered_map<T1,T2>ump){for(auto&x:ump){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::unordered_set<T1>ust){for(auto&x:ust){out<<x<<" ";}out<<"\n";return out;}template<typename T1>std::ostream&operator<<(std::ostream&out,std::set<T1>st){for(auto&x:st){out<<x<<" ";}out<<"\n";return out;}template<typename T1,typename T2>std::ostream&operator<<(std::ostream&out,std::map<T1,T2>mp){for(auto&x:mp){out<<"key: "<<x.first<<", val: "<<x.second<<"\n";}out<<"\n";return out;}template<typename T>void show(T a[],int beg,int end){for(int i=beg;i<=end;i++){std::cout<<a[i]<<" ";}std::cout<<"\n";}

int n;
signed main(){
    std::cin>>n;
    int sum=0;
    getchar();
    while (n--){
        std::string s;
        std::getline(std::cin,s);
        if (s[0]=='i'){
            int num=0;
            if (s[3]=='['){
                bool beg=false;
                for (int i=5;i<s.size();i++){
                    if (!beg && s[i]=='['){
                        beg=true;
                        continue;
                    }
                    if (s[i]==']'){
                        sum+=num*4;
                        num=0;
                        beg=false;
                        continue;
                    }
                    if (beg && isdigit(s[i])){
                        num=num*10+(s[i]-'0');
                    }
                }
            }
            else{
                int num=0;
                for (int i=0;i<s.size();i++){
                    if (s[i]=='='){
                        num++;
                    }
                }
                sum+=num*4;
            }
        }
        else if (s[0]=='l'){
            int num=0;
            if (s[4]=='['){
                bool beg=false;
                for (int i=6;i<s.size();i++){
                    if (!beg && s[i]=='['){
                        beg=true;
                        continue;
                    }
                    if (s[i]==']'){
                        sum+=num*8;
                        num=0;
                        beg=false;
                        continue;
                    }
                    if (beg && isdigit(s[i])){
                        num=num*10+(s[i]-'0');
                    }
                }
            }
            else{
                int num=0;
                for (int i=0;i<s.size();i++){
                    if (s[i]=='='){
                        num++;
                    }
                }
                sum+=num*8;
            }
        }
        else if (s[0]=='S'){
            int num=0;
            bool beg=false;
            for (int i=0;i<s.size();i++){
                if (!beg && s[i]=='\"'){
                    beg=true;
                    continue;
                }
                if (beg && s[i]=='\"'){
                    beg=false;
                    continue;
                }
                if (beg){
                    num++;
                }
            }
            sum+=num;
        }
    }
    /*
    B -> KB --> MB --> GB
    }
    */
    if (sum>=1073741824){
        //GB
        int gb=sum/1073741824;
        std::cout<<gb<<"GB";
        sum-=gb*1073741824;
        if (sum==0){
            return 0;
        }

        int mb=sum/1048576;
        std::cout<<mb<<"MB";
        sum-=mb*1024*1024; //551458
        if (sum==0){
            return 0;
        }

        //
        int kb=sum/1024;  //538个kb
        std::cout<<kb<<"KB";
        sum-=kb*1024;      //546
        if (sum==0){
            return 0;
        }

        std::cout<<sum<<"B\n";
    }
    else if (sum>=1048576){
        int mb=sum/1048576;
        std::cout<<mb<<"MB";
        sum-=mb*1024*1024; //551458
        if (sum==0){
            return 0;
        }
        
        int kb=sum/1024;  //538个kb
        std::cout<<kb<<"KB";
        sum-=kb*1024;      //546
        if (sum==0){
            return 0;
        }
        std::cout<<sum<<"B";
    }
    else if (sum>=1024){
        int kb=sum/1024;  //538个kb
        std::cout<<kb<<"KB";
        sum-=kb*1024;      //546

        if (sum==0){
            return 0;
        }

        std::cout<<sum<<"B";
    }
    else{
        std::cout<<sum<<"B";
    }
    return 0;
}