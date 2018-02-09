import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Scanner;

class WinterComming {

	public static boolean isPrime(int ele){

		if(ele==1){
			return false;
		}

		for(int i=2;i<=(ele/2);i++){
			if(ele%i==0){
				return false;
			}
		}
		return true;
	}


	public static int willSave(int[] a,int n, int k){
		int power=k;
		for(int i=0;i<a.length;i++){
			if(isPrime(a[i])){
				power=k;
			}else{
				if(power==0){
					return 0;
				}else{
					power=power-1;
				}
			}
		}
		return 1;
	}


	public static void main (String[] args) {

		int [] a={1, 2, 10, 4, 6, 8};

		System.out.println("output==> "+willSave(a,6,3));

		// Scanner s = new Scanner(System.in);
		// int testCases=s.nextInt();
		// for (int i=0; i<testCases;i++){
		// 	int n=s.nextInt();
		// 	int k=s.nextInt();
		// 	int [] a = new int[n+1];
		// 	for(int p=0;p<n;p++){
		// 		a[p]=s.nextInt();
		// 	}
		// 	System.out.println("output==> "+willSave(a,n,k));
		// }
	}
}