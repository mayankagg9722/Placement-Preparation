import java.util.Scanner;


public class StarPattern {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.println("Enter number of rows : ");
		int totalRows = s.nextInt();
		int stars, spaces;
		
		if(totalRows % 2 != 0) {
			stars = totalRows/2;
			spaces = 1;
		}
		else {
			stars = totalRows/2 - 1;
			spaces = 2;
		}
		boolean increasing = true;

		for(int currentRow = 1; currentRow <= totalRows; currentRow++) {
			if(currentRow == 1 || currentRow == totalRows) {
				for(int col = 1; col <= totalRows; col++) {
					System.out.print("*");
				}
				System.out.println();
			}
			else {
				for(int i = 1; i <= stars; i++) {
					System.out.print("*");
				}
				for(int j = 1; j <= spaces; j++) {
					System.out.print(" ");
				}
				for(int i = 1; i <= stars; i++) {
					System.out.print("*");
				}
				System.out.println();

				if(stars == 1) {
					increasing = false;
				}

				if(increasing) {
					stars--;
					spaces += 2;
				}
				else {
					stars++;
					spaces -= 2;
				}
			}
		}
	}

}
