import myPackage.MyMath;
import java.util.Scanner;

public class cos {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of x (in radians): ");
        double x = sc.nextInt();
        System.out.println("Enter the number of terms n: ");
        double n = sc.nextInt();

        double cosX = 1;
        int sign = -1;

        for (int i = 1; i < n; ++i) {
            int exp = 2 * i;
            double term = sign * MyMath.power(x, exp) / MyMath.fact(exp);

            cosX += term;
            sign *= -1;
        }

        System.out.println("Cosine of x using the series: " + cosX);
        sc.close();
    }
}
