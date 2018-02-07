#include<iostream>
#include<string.h>
using namespace std;
void removeDuplicates(string s,int i){
	
	if(s[i]=='\0'){
		cout<<s;
		return;
	}

	if(s[i]==s[i+1]){
		char match=s[i];
		int j=i;
		while(s[j]==match){
			int p=j;
			while(s[p]!='\0'){
				s[p]=s[p+1];
				p=p+1;
			}
		}
		removeDuplicates(s,i);
	}else{
		removeDuplicates(s,i+1);
	}

}
int main()
{
	string s;
	cin>>s;
	int size=s.length();
	removeDuplicates(s,0);
	return 0;
}