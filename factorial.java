import java.util.Scanner;  

public class factorial {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);  
		System.out.print("Enter the number:");
		long factOf = sc.nextInt();
		System.out.print("Factorial of the above number is:");
		System.out.println(findFactorial(factOf));
		sc.close();  
	}
	
	public static long findFactorial(long number) {
		if(number == 0) {
			return 1;
		} 
		return number* findFactorial(number-1);
	}

}
