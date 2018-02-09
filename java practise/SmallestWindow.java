import java.util.*;
import java.util.Scanner;

public class SmallestWindow{

	public static ArrayList<String> window;
	public static ArrayList<Boolean> boolArray;


	public static void makeArrayWindow(String k2){
		for(int i=0;i<k2.length();i++){
				window.add(String.valueOf(k2.charAt(i)));
				boolArray.add(false);
			}
	}

	public static void changeBoolArray(char ch){
		for(int i=0;i<window.size();i++){
				if(window.get(i).equals(String.valueOf(ch))){
					boolArray.set(i,true);
				}
			}
	}

	public static boolean isDone(){
		int count=0;
		for(int i=0;i<boolArray.size();i++){
				if(boolArray.get(i).equals(true)){
					count=count+1;
				}
			}
		if(count==boolArray.size()){
			return true;
		}else {
			return false;
		}
	}

	public static void checkSmallWindow(String k1,String k2){

		int max_count=10000;
		int startIndex=-1;
		int endindex=-1;
		
		for (int i=0;i<k1.length();i++){
			window = new ArrayList<String>();
			boolArray = new ArrayList<Boolean>();
			makeArrayWindow(k2);
			int count=0;
			for(int j=i;j<k1.length();j++){
				changeBoolArray(k1.charAt(j));
				count++;
				if(isDone()){
					if(max_count>count){
						max_count=count;
						endindex=j;
						startIndex=i;
					}
				}
			}
		}
		if(endindex!=-1){
			// System.out.println(String.valueOf(window));
			// System.out.println(String.valueOf(boolArray));
			// System.out.println(String.valueOf(startIndex));
			// System.out.println(String.valueOf(endindex));
			StringBuilder builder = new StringBuilder();
			for(int i=startIndex;i<=endindex;i++){
				builder.append(k1.charAt(i));
			}
			System.out.println(builder);
		}
	}

	public static void main(String[] args) {

		// Scanner s = new Scanner(System.in);
		// System.out.println("Enter Strings");
		// String k1=s.nextLine();
		// String k2=s.nextLine();
		// checkSmallWindow(k1,k2);

		checkSmallWindow("zoomlazapzo","oza");
		
	}
}
