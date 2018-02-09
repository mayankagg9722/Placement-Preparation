import java.util.*;
import java.lang.*;

public class ToggleBit{

	public static ArrayList<Integer> toggle(ArrayList<Integer> k,int l,int r){
		
		for(int i=l-1;i<=r-1;i++){
			if(k.get(i) == 1 ){
				k.set(i,0);
			}else{
				k.set(i,1);
			}
		}
		return k;
	}


	public static ArrayList<Integer> findBinaryNumber(int n){
		ArrayList<Integer> stack=new ArrayList<Integer>();
		ArrayList<Integer> reverseStack=new ArrayList<Integer>();
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
		int t=s.nextInt();

		for(int g=0;g<t;g++){
			int number=s.nextInt();
			int l=s.nextInt();
			int r=s.nextInt();

			ArrayList<Integer> binary=findBinaryNumber(number);
			ArrayList<Integer> toggleArray=(toggle(binary,l,r));
			String binaryString="";
			for(int i=toggleArray.size()-1;i>=0;i--){
				binaryString+=String.valueOf(toggleArray.get(i));
			}
			System.out.println(Integer.parseInt(binaryString,2));

		}
	}
}