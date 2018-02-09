import java.util.*;
import java.util.Scanner;

public class minimumOperation{

	public static void minimumOperationNumber(int n,int max_count){
		
		if(n<=3){
			max_count=max_count+n;
			System.out.println("count: "+max_count);
			return;
		}

		if(n%2==0){
			max_count=max_count+1;
		}else{
			max_count=max_count+2;
		}
		minimumOperationNumber(n/2,max_count);

	}

	public static void main(String[] args) {
		int n=8;
		int max_count=0;
		minimumOperationNumber(n,max_count);
	}
}