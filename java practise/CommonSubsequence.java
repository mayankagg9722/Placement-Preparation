import java.util.*;
import java.util.Scanner;

public class CommonSubsequence{

	// str2=>small
	// str1=>large

	public static void getCountSubSequence(String str1,String str2,int max_count){
		int l1=str1.length();
		int l2=str2.length();
		int loop_count=0;
		int flag=0;
		if(l1<l2){
			loop_count=l1;
		}else{
			loop_count=l2;
		}
		loop_count=6;

		for(int i=0;i<loop_count;i++){
			int internal_count=0;
			int p=i;
			int j=0;
			int foundIndex=0;
			while(p<loop_count){
			char char_str2=str2.charAt(p);
			j=foundIndex;
			while(j<l1){
				if(str1.charAt(j) == char_str2){
					foundIndex=j;
					internal_count++;
					break;
				}
				j++;
			}
				p++;
			}
			if(max_count<internal_count){
				max_count=internal_count;
			}
		}

		System.out.println("max_count: "+max_count);

	}

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		System.out.println("Eneter string 1");
		String str1=s.nextLine();
		System.out.println("Eneter string 2");
		String str2=s.nextLine();
		int max_count=-1;
		getCountSubSequence(str1,str2,max_count);
	}
}
