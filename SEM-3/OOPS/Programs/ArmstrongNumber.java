public class ArmstrongNumber {
    
    // Static Method to check if a number is Armstrong Number
    public static boolean isArmstrongNumber(int number) {
        int sum = 0;
        int temp = number;
        while (temp != 0) {
            int remainder = temp % 10;
            sum += Math.pow(remainder, 3);
            temp /= 10;
        }
        return sum == number;
    }

    // Non-Static method to display Armstrong Numbers in a range
    public void display(int start, int end) {
        for (int i = start; i <= end; i++) {
            if (isArmstrongNumber(i)) {
                System.out.println(i + " ");
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        ArmstrongNumber armstrongNumber = new ArmstrongNumber();
        armstrongNumber.display(1, 10000);
    }
}