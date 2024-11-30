package trials;

import java.util.Scanner;

public class Armstrong {
    public static boolean isArmstrong(int n) {
        int sum = 0;
        int temp = n;
        int digit = String.valueOf(n).length();
        while (temp > 0) {
            int ld = temp % 10;
            sum += Math.pow(ld, digit);
            temp /= 10;
        }
        return sum == n;
    }

    public static void display(int low, int high) {
        for (int i = low; i <= high; ++i) {
            if (isArmstrong(i)) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the lower bound: ");
        int low = sc.nextInt();
        System.out.print("Enter the upper bound: ");
        int high = sc.nextInt();
        display(low, high);
        sc.close();
    }
}