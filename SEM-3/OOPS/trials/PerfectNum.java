package trials;

import java.util.Scanner;

public class PerfectNum {
    public static boolean isPerfect(int n) {
        int sum = 0;
        for (int i = 1; i <= n/2; ++i) {
            if (n % i == 0) sum += i;
        }
        return sum == n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the lower bound: ");
        int low = sc.nextInt();
        System.out.print("Enter the upper bound: ");
        int high = sc.nextInt();
        for (int i = low; i <= high; ++i) {
            if (isPerfect(i)) {
                System.out.print(i + " ");
            }
        }
        System.out.println();   
        sc.close();
    }
}
