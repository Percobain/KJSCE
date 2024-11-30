public class KaprekarNumber {
    static boolean kaprekar(int n) {
        if (n == 1) return true;
        int square = n * n;
        while (square != 0) {
            square /= 10;
        }
        square = n * n;
        for (int i = 1; i < n; ++i) {
            int eq_part = (int)Math.pow(10, i);
            if (eq_part == n) continue;
            int sum = square/eq_part + square % eq_part;
            if (sum == n) return true;
        }
        return false;
    }
    
    public static void main(String[] args) {
        for (int i = 1; i < 1000; ++i) {
            if (kaprekar(i)) {
                System.out.print(i + " ");
            }
        }
    }
}