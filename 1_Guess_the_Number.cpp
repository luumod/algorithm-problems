#include <bits/stdc++.h>

int main(){
    int l=1,r=1000000;
    while (l!=r){
        int mid = (l+r+1)>>1;
        printf("%d\n",mid);
        fflush(stdout);
        
        char str[3];
        scanf("%s",str);
        if (strcmp(str,"<")==0){
            r = mid - 1;
        }
        else{
            l = mid;
        }
    }
    printf("! %d\n",l);
    fflush(stdout);
	return 0;
}