import java.util.*;
import java.util.Scanner;

public class maxCoins{

	public static int max_near(int [] a,int c ){
		for(int i=0;i<a.length;i++){
			if(a[i]>c){
				return a[i-1];
			}
		}
		return 0;
	}

	public static void findMaxCoins(int[] a, int c, int max_coins){
		if(c==0){
			System.out.println("Max Coins: "+max_coins);
			return;
		}
		int coinValue=max_near(a,c);
		System.out.println(c/coinValue+" Coin needed: "+coinValue);
		max_coins=max_coins+(c/coinValue);
		c=c%coinValue;
		findMaxCoins(a,c,max_coins);
	}

	public static void main(String[] args) {
		int[] a={1,2,5,10,20,50,100,500,1000};
		int max_coins=0;
		Scanner s =new Scanner(System.in);
		System.out.println("enter currency:");
		int c=s.nextInt();
		findMaxCoins(a,c,max_coins);
	}
}