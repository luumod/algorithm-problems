#include <bits/stdc++.h>

int main(){
    int a,b,c;
    std::cin>>a>>b>>c;
    std::vector<int> nums;
    int num1 = (a*b)+c;
    int num2 = (a*b)*c;
    int num3 = (a+b)+c;
    int num4 = (a+b)*c;
    int num5 = a+(b*c);
    int num6 = a+(b+c);
    int num7 = a*(b+c);
    int num8 = a*(b*c);
    nums.push_back(num1);
    nums.push_back(num1);
    nums.push_back(num3);
    nums.push_back(num4);
    nums.push_back(num5);
    nums.push_back(num6);
    nums.push_back(num7);
    nums.push_back(num8);
    std::cout<<*max_element(nums.begin(),nums.end());
	return 0;
}