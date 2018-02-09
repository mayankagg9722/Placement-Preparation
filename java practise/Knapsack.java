import java.util.*;

public class Knapsack{

	public static void main(String[] args) {
		int[] w={10, 20, 30};
		int[] v={60, 100, 120};
		int max_wt=50;
		int[][] k = new int[w.length+1][max_wt+1];
		for(int i=0;i<=w.length;i++){
			for(int j=0;j<=max_wt;j++){
				if(i==0 || j==0){
					k[i][j]=0;
				}else {
					if(j<w[i-1]){
						k[i][j]=k[i-1][j];
					}else{
						int diff=(j-w[i-1]);
						if((k[i-1][diff]+v[i-1])>k[i-1][j]){
							k[i][j]=(k[i-1][diff]+v[i-1]);
						}else{
							k[i][j]=k[i-1][j];
						}
					}
				}
			}	
		}
		System.out.println("k is:"+k[w.length][max_wt]);
		
	}
}