#include <stdio.h>
int n,k;
void kill(int i,int arr[],int totalperson,int counter){
	
	if(totalperson==1){
		for(int i=1;i<=n;i++){
			if(arr[i]==0){
				printf("%d\n",i);
				break;
			}
		}
		return;
	}

	if(i>n){
		i=1;
	}

	if(counter==k-1 && arr[i]!=-1){
		totalperson=totalperson-1;
		arr[i]=-1;
		counter=0;
	}else if(arr[i]!=-1){
		counter=counter+1;
	}

	kill(i+1,arr,totalperson,counter);

}

int main()
{
	scanf("%d %d",&n,&k);
	int arr[n+1];
	for(int i=1;i<=n;i++){
		arr[i]=0;
	}
	int totalperson=n;
	int counter=0;
	kill(1,arr,totalperson,counter);

	return 0;
}