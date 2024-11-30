package trials;

import java.util.Scanner;

public class Kaprekar {
    public static boolean isKaprekar(int n) {
        if (n == 1) return true;
        int sq = n * n;
        while (sq > 0) {
            sq /= 10;
        }
        sq = n * n;
        for (int i = 1; i < n; ++i) {
            int eq_pt = (int) Math.pow(10, i);
            if (eq_pt == n) continue;
            int sum = sq / eq_pt + sq % eq_pt;
            if (sum == n) return true;
        }
        return false;
    }

    public static void display(int low, int high) {
        for (int i = low; i <= high; ++i) {
            if (isKaprekar(i)) {
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
