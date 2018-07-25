package L8;

public class Recursion {

	public static String[] subsequences(String s) {
		if(s.length() == 0) {
			String out[] = new String[1];
			out[0] = "";
			return out;
		}
		
		String ans[] = subsequences(s.substring(1));
		String output[] = new String[2*ans.length];
		int j = 0;
		for(int i = 0; i < ans.length; i++) {
			output[j] = ans[i];
			j++;
		}
		for(int i = 0; i < ans.length; i++) {
			output[j] = s.charAt(0) + ans[i];
			j++;
		}
		
		return output;
	}
	
	/*public static void keypad(int n, String output) {
		if(n == 0) {
			System.out.println(output);
			return;
		}
		String[] ans = helper(n % 10);
		for(int i = 0; i < ans.length; i++) {
			keypad(n/10, ans[i] + output);
		}
		
	}*/
	
	public static void printSubsequence(String s, String output) {
		if(s.length() == 0) {
			System.out.println(output);
			return;
		}
		
		printSubsequence(s.substring(1), output + s.charAt(0));
		printSubsequence(s.substring(1), output);
	}
	
	public static void main(String[] args) {
		String s = "abc";
		/*String ans[] = subsequences(s);
		for(int i = 0; i < ans.length; i++) {
			System.out.println(ans[i]);
		}*/
		
		printSubsequence(s, "");
	}

}
