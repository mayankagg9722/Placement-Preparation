import java.util.*;
import java.util.Scanner;

public class consecutiveInteger{

	public static int [] sortArray(int [] a){

		for (int i=0;i<a.length;i++){
			for (int j=0;j<a.length;j++){
				if(a[i]<a[j]){
					int t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
			}
		}
		return a;
	}

	public static void checkConsecutive(int [] a){

		int max_count=0;

		int [] sortArray=sortArray(a);

		for (int i=0;i<sortArray.length;i++){
			if((a[i+1]-a[i])>1){
				max_count++;
				System.out.println(String.valueOf(max_count));
				break;
			}else{
				max_count++;
			}
		}

	}

	public static void main(String[] args) {

		int[] a={2, 6, 1, 9, 4, 5, 3};

		checkConsecutive(a);		
	}
}