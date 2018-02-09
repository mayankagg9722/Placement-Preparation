import java.util.*;
import java.lang.*;

public class BitManipulation{

	


	public static void main(String[] args) {
		Scanner s= new Scanner(System.in);
		// System.out.println("Enter a number:");
		// int number=s.nextInt();




		// Shifting

		// System.out.println(Integer.toBinaryString(9));
		// System.out.println(Integer.toBinaryString(9<<1));
		// System.out.println(Integer.toBinaryString(9>>1));
		// System.out.println(Integer.toBinaryString(120>>>1));

		// System.out.println(Integer.toBinaryString(9));
		// System.out.println(Integer.toBinaryString(9>>2));
		// System.out.println(Integer.toBinaryString(9>>>2));

		System.out.println(Integer.toBinaryString(11));


		// RIGHT SHIFT EVEN BITS OF BINARY NUMBER OF 11

		// System.out.println(Integer.toBinaryString((11 & 0xAAAAAAAA)>>1));


		// LEFT SHIFT ODD BITS OF BINARY NUMBER OF 11
		// System.out.println(Integer.toBinaryString((11 & 0x55555555)<<1));


		System.out.println(Integer.toBinaryString(((11 & 0xAAAAAAAA)>>1) | ((11 & 0x55555555)<<1)));
		



		// System.out.println(Integer.toBinaryString(1));
		// System.out.println(Integer.toBinaryString(1<<1));
		// System.out.println(Integer.toBinaryString(1<<2));
		// System.out.println(Integer.toBinaryString(1>>2));


		// calculate XOR of two numbers 
		int xor= 3^4;
		// System.out.println("Bitwise: "+String.valueOf(xor));
	}
}