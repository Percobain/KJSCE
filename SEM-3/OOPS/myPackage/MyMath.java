package myPackage;

public class MyMath {
    public static double power(double x, int y) {
        double res = 1;
        for (int i = 0; i < y; ++i) {
            res *= x;
        }
        return res;
    }

    public static int fact(int x) {
        int fact = 1;
        for (int i = 1; i <= x; ++i) {
            fact *= i;
        }
        return fact;
    }
}
