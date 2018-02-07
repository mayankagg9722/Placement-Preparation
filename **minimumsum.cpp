#include<iostream>
using namespace std;
int a[4]={36 ,7 ,46 ,40};
int findMinimumSum(int netsum,int sum,int i){
	if(i==3){
		return abs((netsum-sum)-sum);
	}

	return min(findMinimumSum(netsum,sum+a[i],i+1),findMinimumSum(netsum,sum,i+1));
}
int main()
{
	int sum=0;
	for (int i=0;i<5;i++){
		sum+=a[i];
	}
	int k=findMinimumSum(sum,0,0);
	cout<<"K:"<<k;
	return 0;
}