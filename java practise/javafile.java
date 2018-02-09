import java.util.Scanner;
import static java.lang.Math.pow;

public class javafile	{

	public static void question1()	{
		Scanner s  = new Scanner(System.in);
		System.out.println("Enter number");
		int n = s.nextInt();
		System.out.println("Press 1 for sum \n Press 2 for product");
		int x = s.nextInt();
		int sum = 0;
		int prod = 1;
		if(x == 1)	{
			for(int i = 1; i <= n; i++)	{
				sum += i;
			}
			System.out.println(sum);
		}
		else if(x == 2)	{
			for(int i = 1; i <= n; i++)	{
				prod *= i;
			}
			System.out.println(prod);
		}
		else	{
			System.out.println("Incorrect Option");
		}

	}

	public static void power()	{
		Scanner s = new Scanner(System.in);
		System.out.println("Enter no. and power");
		int x = s.nextInt();
		int m = s.nextInt();
		System.out.println(Math.pow(x, m));
	}

	public static void reverse()	{
		Scanner s = new Scanner(System.in);
		System.out.println("Enter a number");
		int num = s.nextInt();
		int last = 0;
		int reverse = 0;
		while(num > 0)	{
			last = num % 10;
			num = num / 10;
			reverse = reverse * 10 + last;
		}
		System.out.println(reverse);
	}

	public static void question5()	{
		int n = 0;
		for(int i = 1; i <= 20; i++)	{
			n = 3 * i + 2;
			if(n % 4 != 0)	{
				System.out.println(n);
			}
		}
	}

	public static void binaryToDecimal()	{
		Scanner s = new Scanner(System.in);
		System.out.println("Enter a Binary Number");
		int num = s.nextInt();
		int n = num;
		double sum = 0;
		int len = 0;
		while(n > 0)	{
			n = n / 10;
			len++;
		}
		for(int i = 0; i < len; i++)	{
			sum = sum + ((num % 10) * Math.pow(2, i));
			num = num / 10;
		}
		System.out.println(sum);
	}

	public static void decimalToBinary()	{
		Scanner s = new Scanner(System.in);
		System.out.println("Enter a Decimal Number");
		int num = s.nextInt();
		int binary[] = new int[25];
		int index = 0;
		while(num > 0)	{
			int quot = num % 2;
			num = num / 2;
			binary[index] = quot;
			index++;
		}
		for(int i = index-1; i >= 0; i--)	{
			System.out.print(binary[i]);
		}
		System.out.println();
	}

	public static void sqrtOfNumber()	{
		Scanner s = new Scanner(System.in);
		System.out.println("Enter a number");
		int num = s.nextInt();
		double decimal = Math.sqrt(num);
		System.out.println("Integral part => " + (int)Math.sqrt(num));
		System.out.println("Enter the accuracy number");
		int a = s.nextInt();
		int newNumber = (int)(decimal * Math.pow(10, a));
		System.out.println(newNumber/Math.pow(10, a));
	}

	public static void question9()	{
		Scanner s = new Scanner(System.in);
		System.out.println("Enter a number");
		int n = s.nextInt();
		int num[] = new int[n];
		int count = 0;
		System.out.println("Enter the numbers");
		for(int i = 0; i < n; i++)	{
			num[i] = s.nextInt();
		}
		for(int j = 0; j < n-1; j++)	{

			if(num[j] > num[j+1])	{
				if(count == 0)	{
					continue;
				}
				else	{
					System.out.println("NO");
					return;
				}
			}
			else if(num[j] < num[j+1])	{
				count++;
			}
		}
		System.out.println("YES");
		
	}

	public static void main(String[] args)	{
		question1();
		// power();
		// reverse();
		// question5();
		// binaryToDecimal();
		// decimalToBinary();
		// sqrtOfNumber();
		// question9();
	}

}