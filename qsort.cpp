#include<stdio.h>
#include<stdlib.h>

int compare (const void * a, const void * b)
{
  return ( *(long long int*)a - *(long long int*)b );
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--){
		long long int n,k;
		scanf("%lld %lld",&n,&k);
		if(n>0){
			int flag=0;
			long long int a[n];
			for(int i=0;i<n;i++){
				long long int no;
				scanf("%lld",&no);
				a[i]=no;
			}
			qsort (a,n, sizeof(long long int), compare);
			long long int j=0;
			for(long long int i=0;i<a[n-1];i++){
				if(i!=a[j]){
					if(k>0){
						k=k-1;
					}else{
						flag=1;
						printf("%lld\n",i);
						break;
					}
				}else{
					j++;
				}
			}
			if(flag==0){
				if(k>0){
					printf("%lld\n",a[n-1]+k+1);
				}else{
					printf("%lld\n",a[n-1]+1);
				}
			}
		}
	}
	return 0;
}