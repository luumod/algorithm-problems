#include <bits/stdc++.h>

const int N=34;
int dp[N][N]; //dp[i][j]在往后i个位置可以放置j个1 
int x,y,k,b;
void init(){
	for (int i=0;i<N;i++){
		dp[i][0]=1; 
	}
	for (int i=1;i<N;i++){
		for (int j=1;j<N;j++){
			//相当于求组合数：
			//dp[i-1][j-1]表示选择这个数字，则还需在剩下的位置放置j-1个1
			//dp[i-1][j]表示不选择这个数字，则还需在i-1个位置放置j个1
			dp[i][j]=dp[i-1][j-1]+dp[i-1][j]; 
		}
	}
}
int solve(int num){
	if (!num){
		return 0;
	}
	std::vector<int> vec;
	while (num){
		vec.push_back(num%b);
		num/=b;
	}
	int ans=0;
	int last=0; //表示已经放置了多少个1
	for (int i=vec.size();i>=1;i--){
		int now=vec[i-1];
		if (now){ //如果当前位置是 1或者大于1
			ans+=dp[i-1][k-last]; //第i位放置0，则剩下还需放k-last个1
			if (now>1){ //第i位大于1
				if (k-last-1>=0){
					ans+=dp[i-1][k-last-1];
				}
				break; //第i位放大于1的数字，不符合
			}
			else{
				//第i位放置1，则last++
				last++;
				if (last>k){
					break;
				}
			}
		}	
		if (i==1 && last==k){
			ans++;
		}
	}
	return ans;
}
int main(){
	init();
	//在[x,y]区间内是否存在数字满足：这个数字恰好等于k个b的整数幂的和
	std::cin>>x>>y>>k>>b;
	// k=2, b=2:  17 = 2^4 + 2^0 ... 
	/*
	可以转换为b进制： 10001 即判断在 b进制中是否存在k个1
	*/
	std::cout<<solve(y)-solve(x-1);

	return 0;
}