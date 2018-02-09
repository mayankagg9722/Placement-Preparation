import java.util.*;

public class LRU{

	public static Boolean alreadyPresent(ArrayList<Integer> k, int value){
		for(int i=0;i<k.size();i++){
			if(k.get(i)==value){
				return true;
			}
		}
		return false;
	}

	public static void findPagefault(int [] a,int range){
		ArrayList<Integer> k=new ArrayList<Integer>();
		int fault=0;
		for (int i=0;i<a.length;i++){
			int newPage=a[i];
			if(k.size()==4){
				if(!(alreadyPresent(k,newPage))){
					fault++;
					k.remove(0);
					k.add(newPage);
				}else {
					continue;
				}
			}else{
				fault++;
				k.add(newPage);
			}
		}
		System.out.println("working: "+fault);
	} 

	public static void main(String[] args) {
		// int [] a={5, 0, 1, 3, 2, 4, 1, 0, 5};
		int [] a={3, 1, 0, 2, 5, 4, 1, 2};
		int range=4;
		findPagefault(a,range);
	}
}