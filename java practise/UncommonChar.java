import java.util.*;
import java.util.Scanner;


public class UncommonChar{

	public static boolean notIn(ArrayList<String> str,char ch){
		for (int i=0;i<str.size();i++){
			if(String.valueOf(ch)==str.get(i)){
				return false;
			}
		}
		return true;
	}

	public static void uncommon(String k1,String k2,ArrayList<String> uncommon){
		
		for(int i=0;i<k1.length();i++){
			char ch = k1.charAt(i);
			int flag=0;
			for(int j=0;j<k2.length();j++){
				if(k2.charAt(j)==ch){
					flag=1;
				}
			}
			if(flag==0){
				if(notIn(uncommon,ch)){
					uncommon.add(String.valueOf(ch));
				}
			}
		}
	
	}

		

	public static void main(String[] args) {
		ArrayList<String> uncommon= new ArrayList<String>();
		Scanner s = new Scanner(System.in);
		System.out.println("Enter a string");

		String k1=s.nextLine();
		String k2=s.nextLine();

		System.out.println("String1 is: "+k1);
		System.out.println("String2 is: "+k2);

		uncommon(k1,k2,uncommon);
		uncommon(k2,k1,uncommon);
		System.out.println("uncommon character is: "+uncommon);
	}
}