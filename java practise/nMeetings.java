import java.util.*;
import java.util.Scanner;

public class nMeetings{

	public static void sort(int [] a,int [] b ){
		for(int i=0;i<b.length;i++){
			for(int j=0;j<b.length-1;j++){
				if(b[j]>b[j+1]){
					int t=a[j+1];
					a[j+1]=a[j];
					a[j]=t;

					t=b[j+1];
					b[j+1]=b[j];
					b[j]=t;
				}
			}
		}
	}

	public static void findMaxMeetings(int [] a, int [] b ){
		sort(a,b);
		int max_count=-1;
		for (int i=0;i<b.length;i++){
			// System.out.println("a: "+a[i]);
			// System.out.println("b: "+b[i]);
			int count=0;
			int finish_prev_time=b[i];
			for(int j=i+1;j<b.length;j++){
				if(a[j]>=finish_prev_time){
					count++;
				}
			}
			if(max_count<count){
				max_count=count;
			}
		}
		System.out.println("max_meetings: "+max_count);
	}

	public static void main(String[] args) {
		int[] a={75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924};
		int[] b={112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252};

		// int[] a={1, 3, 0, 5, 8, 5};
		// int[] b= {2,4, 6, 7, 9, 9};
		findMaxMeetings(a,b);
	}
}