import java.util.Scanner;

public class SeriesSum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter value of n: ");
        int n = scanner.nextInt();
        scanner.close();

        double sum = 0.0;
        for (int i = 1; i <= n; ++i) {
            sum += 1.0 / i;
        }
        System.out.println("The sum of the series is: " + sum);
    }
}   
