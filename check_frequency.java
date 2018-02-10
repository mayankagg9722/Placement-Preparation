import java.util.*;
import java.util.Scanner;
import java.lang.*;

public class check_frequency{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t=sc.nextInt();
		while(t>0){
			Scanner stsc = new Scanner(System.in);
			String str = stsc.nextLine();
			HashMap<String,Integer> hash = new HashMap<>();
			for(int i=0;i<str.length();i++){
				String c = Character.toString(str.charAt(i));
				if(hash.isEmpty()){
					hash.put(c,1);
				}else if(hash.containsKey(c)){
					int k = hash.get(c);
					k=k+1;
					hash.put(c,k);
				}else{
					hash.put(c,1);
				}
			}
			int min=str.length();
			for(Map.Entry<String,Integer> entry : hash.entrySet()){
				if(min>entry.getValue()){
					min=entry.getValue();
				}
			}
			int x=0;
			int y=0;
			for(Map.Entry<String,Integer> entry : hash.entrySet()){
				if(min+1==entry.getValue()){
					x=x+1;
				}
				if(min==entry.getValue()){
					y=y+1;
				}
			}
			if((x==1 && ((x+y)==str.length()-1)) || (y==str.length()-1)){
				System.out.println("1");
			}else{
				System.out.println("0");
			}
			t=t-1;
		}	
	}	
}
