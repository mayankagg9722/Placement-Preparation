import java.util.*;
import static java.lang.Math.pow;

public class Subset{

	public static void findSubset(int[] a,int n){
		for (int i=0;i<Math.pow(2,n);i++){
			// System.out.println("i is: "+i);
			for(int j=0;j<n;j++){
				if ((i & (1 << j)) > 0){
					// System.out.println("j is: "+j);
                    System.out.print(a[j] + " ");
				}
			}
			System.out.print("\n");
		}
			
	}

	public static void main(String[] args) {
		int[] a={1,2,3};
		findSubset(a,a.length);
		
	}
}