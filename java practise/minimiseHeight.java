import java.util.*;
import java.util.Scanner;

public class minimiseHeight{

	public static void sort(int [] a){
		for (int i=0;i<a.length;i++){
			for(int j=0;j<a.length-1;j++){
				if(a[j+1]<a[j]){
					int t=a[j+1];
					a[j+1]=a[j];
					a[j]=t;
				}
			}
		}
	}


	public static void minimiseHeights(int [] a, int k){
		sort(a);
		int smallest=a[0]+k;
		int largest=a[a.length-1]-k;
		if(smallest>largest){
			int t=smallest;
			smallest=largest;
			largest=smallest;
		}

		int diff=largest-smallest;


		// System.out.println("working:1: "+diff);

		for(int i=1;i<a.length-1;i++){
			int add=a[i]+k;
			int sub=a[i]-k;
			int d1=-1;
			int d2=-1;
			if(sub>=smallest || add<=largest){
				continue;
			}

			if(add>largest){
				d1 =add-smallest;	
			}

			if(sub >0 && sub<smallest){
				d2=largest-sub;	
			}
		
			if(d1<=d2){
				diff=d1;
				largest=add;
			}else {
				diff=d2;
				smallest=sub;
			}
			
		}

		System.out.println("Final: "+diff);

	}


	public static void main(String[] args) {
	int [] a ={1, 5, 15, 10};
	int k=3;
	minimiseHeights(a,k);
	}
}

