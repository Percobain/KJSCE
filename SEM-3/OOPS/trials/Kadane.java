package trials;

import java.util.Scanner;;

public class Kadane {
    public static long maxSubArray(int arr[]) {
        long maxi = Long.MIN_VALUE;
        long sum = 0;
        
        for (int i = 0; i < arr.length; ++i) {
            sum += arr[i];
            if (sum > maxi) maxi = sum;
            if (sum < 0) sum = 0;
        }
        return maxi;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter the elements: ");
        for (int i = 0; i < n; ++i) arr[i] = sc.nextInt();
        System.out.println("Maximum sum of subarray: " + maxSubArray(arr));
        sc.close();
    }
}
