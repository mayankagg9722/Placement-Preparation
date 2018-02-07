#include<stdio.h>


int totalways(int n){
	if(n<0){
		return 0;
	}

	if(n==0){
		return 1;
	}
	
	return totalways(n-1)+totalways(n-2)+totalways(n-3);
}

int main()
{
	int ways;

	ways=totalways(1);
	printf("Ways:%d\n",ways);

	
	ways=totalways(2);
	printf("Ways:%d\n",ways);

	
	ways=totalways(3);
	printf("Ways:%d\n",ways);

	
	ways=totalways(4);
	printf("Ways:%d\n",ways);

	
	ways=totalways(5);
	printf("Ways:%d\n",ways);

	
	ways=totalways(6);
	printf("Ways:%d\n",ways);

	return 0;
}

