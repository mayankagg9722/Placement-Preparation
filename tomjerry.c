#include <stdio.h>

int main() {
	int t;
	int n;
	scanf("%d",&t);
	while(t--){
	    scanf("%d",&n);
	    if(n%2!=0){
	        printf("0");
	    }else{
	        printf("1");
	    }
	}
	return 0;
}