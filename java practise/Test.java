import java.util.*;
import java.util.Scanner;

public class Test{

	public static int findSubArrayZero(ArrayList<Integer> a){

		int max_count=-1;

		for (int i=0;i<a.size();i++){
			int count=1;
			int sum=0;
			System.out.println(a.get(i));
			sum=sum+a.get(i);
			for (int j=i+1;j<a.size();j++){
				count=count+1;
				sum=sum+a.get(j);
				if(sum==0){
					if(max_count<count){
						max_count=count;
					}
					System.out.println(count);
				}
			}
		}

		return max_count;
	}

	public static void subarray(){
		Scanner s = new Scanner(System.in);
		ArrayList<Integer> a = new ArrayList<Integer>();
		// System.out.println("Enter size of array");
		// int len=s.nextInt();
		// for(int i =0;i<len;i++){
		// 	System.out.println("Enter element");
		// 	int k=s.nextInt();
		// 	a.add(k);
		// }
		// System.out.println("List:"+a.toString());
		a.add(15);
		a.add(-2);
		a.add(2);
		a.add(-8);
		a.add(1);
		a.add(7);
		a.add(10);
		a.add(23);
		int k=0;

		k=findSubArrayZero(a);
		System.out.println("k is:"+k);

	}

public static void main(String[] args) {
	subarray();
}

}