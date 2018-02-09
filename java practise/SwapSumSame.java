import java.util.*;
import java.util.Scanner;

public class SwapSumSame{

	public static int sumArray(int [] k){
		int sum=0;
		for(int j=0;j<k.length;j++){
			sum+=k[j];
		}
		return sum;
	}

	public static int checkswap(int[] a,int[] b){

		int s=-1;
		int s1=0,s2=0,flag=0;;
		s1=sumArray(a);
		s2=sumArray(b);
		int diff=Math.abs((s1-s2))/2;
		for(int i=0;i<a.length;i++){
			s=-1;
			flag=0;
			for(int j=0;j<b.length;j++){
				s=Math.abs(a[i]-b[j]);
				if(s==diff){
					System.out.println("First No:"+a[i]+" Second No:"+b[j]);
					flag=1;
					break;
				}
			}
			if(flag==1){
				break;
			}
		}
		return 0;
	}

	public static void main(String[] args) {
		int [] a={5,7,4,6};
		int [] b={1,2,3,8};
		int k=0;
		k=checkswap(a,b);
		// System.out.println("working"+k);
	}
}