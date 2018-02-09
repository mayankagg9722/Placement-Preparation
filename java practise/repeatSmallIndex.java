import java.util.*;
import java.util.Scanner;


public class repeatSmallIndex{

	public static void checkRepeatAlpha(String k){
		char repeatAlpha='@';
		int diff=100;
		for(int i=0;i<k.length();i++){
			char ch = k.charAt(i);
			for(int j=i+1;j<k.length();j++){
				if(k.charAt(j)==ch){
					if(diff>(j-i)){
						repeatAlpha=ch;
						diff=j-i;
					}
				}
			}
		}
		System.out.println("Repeat character is: "+repeatAlpha);
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.println("Enter a string");

		String k=s.nextLine();

		System.out.println("String is: "+k);

		checkRepeatAlpha(k);

		
	}
}