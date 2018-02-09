import java.util.*;
import java.lang.*;

public class Sparse{

	public static boolean isSparse(String k){
		System.out.println("String is: "+k);
		for(int i=0;i<k.length()-1;i++){
			if(k.charAt(i) == '1' ){
				if(k.charAt(i) == k.charAt(i+1)){
				return false;
				}
			}
		}
		return true;
	}

	public static ArrayList<Integer> findBinaryNumber(int n){
		ArrayList<Integer> stack=new ArrayList<Integer>();
		int r=-1,q=-1;
		while(n!=0){
			r=n%2;
			q=n/2;
			n=q;
			stack.add(r);
		}
		return stack;
	}

	public static void main(String[] args) {
		Scanner s= new Scanner(System.in);
		System.out.println("Enter a number:");
		int number=s.nextInt();



		// Short way
		// System.out.println(isSparse(Integer.toBinaryString(number)));

		//use own fnction to find binary

		ArrayList<Integer> binary=findBinaryNumber(number);
		String binaryString="";
		for(int i=binary.size()-1;i>=0;i--){
			binaryString+=String.valueOf(binary.get(i));
		}
		System.out.println(isSparse(binaryString));
	}
}