package L25;

public class DP {
	
	public static int lcsBruteForce(String s, String t) {
		if(s.length() == 0 || t.length() == 0) {
			return 0;
		}
		if(s.charAt(0) == t.charAt(0)) {
			return 1 + lcsBruteForce(s.substring(1), t.substring(1));
		}
		else {
			int option1 = lcsBruteForce(s, t.substring(1));
			int option2 = lcsBruteForce(s.substring(1), t);
			return Math.max(option1, option2);
		}
	}
	
	public static int lcsBetter(String s, String t) {
		int a[][] = new int[s.length()+1][t.length()+1];
		for(int i = 0; i <= s.length(); i++) {
			for(int j = 0; j <= t.length(); j++) {
				a[i][j] = -1;
			}
		}
		return lcsHelper(s, t, a);
	}
	
	private static int lcsHelper(String s, String t, int [][]a) {
		int m = s.length();
		int n = t.length();
		if(m == 0) {
			a[m][n] = 0;
			return a[m][n];
		}
		if(n == 0) {
			a[m][n] = 0;
			return a[m][n];
		}
		
		if(a[m][n] != -1) {
			return a[m][n];
		}
		
		if(s.charAt(0) == t.charAt(0)) {
			a[m][n] = 1 + lcsHelper(s.substring(1), t.substring(1), a);
		}
		else {
			int option1 = lcsHelper(s, t.substring(1), a);
			int option2 = lcsHelper(s.substring(1), t, a);
			a[m][n] = Math.max(option1, option2);
		}
		return a[m][n];
	}

	public static int lcsIterative(String s, String t) {
		int m = s.length();
		int n = t.length();
		int ans[][] = new int[m+1][n+1];
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				if(s.charAt(m-i) == t.charAt(n-j)) {
					ans[i][j] = 1 + ans[i-1][j-1];
				}
				else {
					ans[i][j] = Math.max(ans[i][j-1], ans[i-1][j]);
				}
			}
		}
		return ans[m][n];
	}
	
	public static int fibonacci(int n) {
		if(n == 0) {
			return 0;
		}
		if(n == 1) {
			return 1;
		}
		return fibonacci(n-1) + fibonacci(n-2);
	}
	
	public static int fibBetter(int n) {
		int a[] = new int[n+1];
		return fibHelper(n, a);
	}
	
	private static int fibHelper(int n, int[] a) {
		if(n == 0) {
			a[0] = 0;
			return 0;
		}
		if(n == 1) {
			a[1] = 1;
			return 1;
		}
		if(a[n] != 0) {
			return a[n];
		}
		a[n] = fibHelper(n-1, a) + fibHelper(n-2, a);
		
		return a[n];
	}
	
	public static int fibIterative(int n) {
		int a[] = new int[n+1];
		a[0] = 0;
		a[1] = 1;
		for(int i = 2; i <= n; i++) {
			a[i] = a[i-1] + a[i-2]; 
		}
		return a[n];
	}

	public static void main(String[] args) {
		String s = "abcedfabcedfabcedfabcedfabcabcedfabcedfabcedfabcedfabcabcedfabcedfabcedfabcedfabc";
		String t = "ba189cf7eba189cf7eba189cf7eba189cf7eba189cf7eba189cf7eba189cf7eba189cf7eba189cf7eba189cf7e";
		System.out.println(lcsBetter(s, t));
//		System.out.println(lcsBruteForce(s, t));
		System.out.println(lcsIterative(s, t));
		
		/*System.out.println(fibBetter(5000));
		System.out.println(fibonacci(50));*/
	}
	
	
	
	
	
	
	
	
}
