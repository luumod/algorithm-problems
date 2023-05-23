#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n;
int a[2005];
int vt[2005];
main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			vt[a[i]]=i;
		}
		if(n==1){
			cout<<a[1]<<endl;
			continue;
		}
		if(vt[n]==1){
			vt[n]=vt[n-1];
		}
		for(int i=vt[n];i<=n;i++)	cout<<a[i]<<" ";
        std::cout<<"\n";
		if(vt[n]!=n){
			cout<<a[vt[n]-1]<<" ";
			vt[n]--;
		}	
        std::cout<<"\n";
		//vt[n]--;
		for(int i=vt[n]-1;i>=1;i--){
			if(a[1]>a[i]){
				for(int j=1;j<=i;j++)	cout<<a[j]<<" ";
				break;
			}	
			else{
				cout<<a[i]<<" ";
			}
		}
		cout<<endl;
	}
    std::cout<<"\n";
    std::cout<<"\n";
}
