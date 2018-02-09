import java.util.*;


// Worst timecomplexity=O(n)


public class KMPPattern{

	public static void makeStringToCharArray(String str,ArrayList<Character> stringChars){
		for(int k=0;k<str.length();k++){
			stringChars.add(str.charAt(k));
		}
	}

	public static void makePrefixArray(String str,ArrayList<Integer> prefix){
		//make list of string characters
		ArrayList<Character> stringChars=new ArrayList<Character>();
		makeStringToCharArray(str,stringChars);
		// System.out.println(""+stringChars);

		//make list of prefix array
		int j=0;
		int i=0;
		while(i<stringChars.size()){
			if(i==0){
				prefix.add(0);
				i++;
			}else{
				if(stringChars.get(j)==stringChars.get(i)){
					prefix.add(j+1);
					j++;
					i++;
				}else{
					if(j!=0){
						j=prefix.get(j-1);
					}
					else{
						prefix.add(0);
						i++;
					}
				}
			}
		}	
	}

	public static void findPattern(String txt,String pattern,ArrayList<Integer> prefix){
		int i=0;
		int j=0;
		while(i<txt.length()){

			if(pattern.charAt(j)==txt.charAt(i)){
				i++;
				j++;
			}else{
				if(j!=0){
					j=prefix.get(j-1);
				}else{
					i++;
				}
			}

			if(j==pattern.length()){
				System.out.println("Found At==> "+(i-j));
				j=prefix.get(j-1);
			}
		}
	}

	public static void main(String[] args) {

		String pattern="abcaby";
		String txt="abxabcabcaby";

		//testpattern
		// String pattern="acacabacacabacacac"; 
		

		ArrayList<Integer> prefix=new ArrayList<Integer>();

		makePrefixArray(pattern,prefix);

		System.out.println("prefix==> "+prefix);

		findPattern(txt,pattern,prefix);
		
	}
}