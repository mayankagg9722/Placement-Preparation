package L9;

import java.util.Scanner;

public class ComplexityAnalysis {

	public static void bubbleSort(int[] a) {
		for(int j = 0; j < a.length; j++) {
			for(int i = 0; i < a.length-1-j; i++) {
				if(a[i] > a[i+1]) {
					int temp = a[i];
					a[i] = a[i+1];
					a[i+1] = temp;
				}
			}
		}
	}
	
	public static int[] mergeSort(int a[]) {
		if(a.length <= 1) {
			return a;
		}
		
		int half1[] = new int[a.length/2];
		int half2[] = new int[a.length - half1.length];
		int k = 0;
		for(int i = 0; i < half1.length; i++) {
			half1[k] = a[i];
			k++;
		}
		k = 0;
		for(int i = half1.length; i < a.length; i++) {
			half2[k] = a[i];
			k++;
		}
		
		half1 = mergeSort(half1);
		half2 = mergeSort(half2);
		
		a = mergeTwoSortedArrays(half1, half2);
		return a;
		
	}

	public static int[] mergeTwoSortedArrays(int[] a, int[] b) {
		int output[] = new int[a.length + b.length];
		int i = 0, j = 0, k = 0;
		while(i < a.length && j < b.length) {
			if(a[i] < b[j]) {
				output[k++] = a[i++];
			}
			else {
				output[k++] = b[j++];
			}
		}
		while(i < a.length) {
			output[k++] = a[i++];
		}
		while(j < b.length) {
			output[k++] = b[j++];
		}
		return output;
	}
	
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int a[] = new int[n];
		for(int i = 0; i < n; i++) {
			a[i] = n - i;
		}
		
		long t1 = System.currentTimeMillis();
		int[] out = mergeSort(a);
		long t2 = System.currentTimeMillis();
		System.out.println("Merge Sort : " + (t2-t1));
		
		t1 = System.currentTimeMillis();
		bubbleSort(a);
		t2 = System.currentTimeMillis();
		System.out.println("Bubble Sort : " + (t2-t1));
		
	}

}
