import java.util.*;

public class candy{

	public static void sort(int [] cost,String str){
		if(str.equals("asc")){
			for(int i=0;i<cost.length;i++){
				for(int j=0;j<cost.length-1;j++){
					if(cost[j+1]<cost[j]){
						int t=cost[j+1];
						cost[j+1]=cost[j];
						cost[j]=t;
					}
				}
			}
		}else {
			for(int i=0;i<cost.length;i++){
				for(int j=0;j<cost.length-1;j++){
					if(cost[j+1]>cost[j]){
						int t=cost[j+1];
						cost[j+1]=cost[j];
						cost[j]=t;
					}
				}
			}
		}
	}

	public static void minCandy(int n, int k,int[] cost){
		sort(cost,"asc");
		int spentMoney=0;
		int j=n-1;
		for(int i=0;i<=j;i++){
			j=j-k;
			spentMoney=spentMoney+cost[i];
		}
		System.out.println("money min : "+spentMoney);

	}

	public static void maxCandy(int n, int k,int[] cost){
		sort(cost,"dsc");
		int spentMoney=0;
		int j=n-1;
		for(int i=0;i<=j;i++){
			j=j-k;
			spentMoney=spentMoney+cost[i];
		}
		System.out.println("money max : "+spentMoney);

	}


public static void main(String[] args) {
	int n=4;
	int k=2;
	int [] cost={1,2,3,4};
	minCandy(n,k,cost);
	maxCandy(n,k,cost);
}

}