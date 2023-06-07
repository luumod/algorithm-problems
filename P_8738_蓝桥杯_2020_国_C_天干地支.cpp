#include<bits/stdc++.h>
using namespace std;
int y, x, n;
string a[10] = { "jia","yi","bing","ding","wu","ji","geng","xin","ren","gui" };
string b[13] = { "zi","chou","yin","mao","chen","si","wu","wei","shen","you","xu","hai" };
int main() {
    cin >> n;
    while (n > 2020){
        n -= 60;
    } 
    while (n < 2020){
        n += 60;
    } 
    x = 6; y = 0;
    for (int i = 2021; i <= n; i++) {
        x++,y++;
        if (x==10){
            x=0;
        }
        if (y==12){
            y=0;
        }
    }
    cout << a[x] << b[y];
    return 0;
}