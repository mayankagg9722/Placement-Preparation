import java.util.*;

// Worst timecomplexity=O(m(n-m+1))

public class NaivePattern{
	public static void findPattern(String txt, String pattern,int txtLength,int patternLength){
		if(txtLength<patternLength){
			System.out.println("Not Found");
		}else {
			for(int i=0;i<(txtLength-patternLength+1);i++){
				int j=0;
				for (j=0;j<patternLength;j++){
					if(!(txt.charAt(i+j)==pattern.charAt(j))){
						break;
					}
				}
				if(j==patternLength){
					System.out.println("pattern found at: "+i);
				}
			}
		}
	}

	public static void main(String[] args) {
		String txt="mayank";
		String pattern="ya";
		findPattern(txt,pattern,txt.length(),pattern.length());
	}
}