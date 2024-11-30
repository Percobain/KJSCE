import myPackage.Trigonometry;
import java.util.Scanner;

public class Main 
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the angle (0, 30, 60, 90): ");
        int degree = sc.nextInt();

        System.out.println("sin(" + degree + ") = " + Trigonometry.sine(degree));
        System.out.println("cos(" + degree + ") = " + Trigonometry.cos(degree));
        System.out.println("tan(" + degree + ") = " + Trigonometry.tan(degree));
        System.out.println("cot(" + degree + ") = " + Trigonometry.cot(degree));
        System.out.println("cosec(" + degree + ") = " + Trigonometry.cosec(degree));
        System.out.println("sec(" + degree + ") = " + Trigonometry.sec(degree));

        sc.close();
    }
}
