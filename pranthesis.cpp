#include<iostream>
#include<string.h>
using namespace std;

void checkFlag(char i ,char j,int *flag){
	if(i=='[' && (j=='}' || j==')')){
		*flag=1;
	}
	if(i=='{' && (j==']' || j==')')){
		*flag=1;
	}
	if(i=='(' && (j==']' || j=='}')){
		*flag=1;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int flag=0;
		int count_circ=0;
		int count_rect=0;
		int count_curl=0;
		for(int i=0;i<s.length();i++){
			
			if(i<s.length()-1){
				checkFlag(s[i],s[i+1],&flag);	
			}

			if(flag==1){
				break;
			}
		
			if(s[i]=='{'){
				count_curl++;
			}else if(s[i]=='}'){
				count_curl--;
			}else if(s[i]=='['){
				count_rect++;
			}else if(s[i]==']'){
				count_rect--;
			}else if(s[i]=='('){
				count_circ++;
			}else if(s[i]==')'){
				count_circ--;
			}
		}
		
		if(flag==0 && count_circ==0 && count_rect==0 && count_curl==0){
			printf("Correct\n");
		}else{
			printf("Incorrect\n");
		}
	}
	
	return 0;
}