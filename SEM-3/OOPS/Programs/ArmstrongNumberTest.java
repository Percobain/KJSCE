// Static and Non-Static methods accessed from another clas
public class ArmstrongNumberTest {

    public static void main(String[] args) {
        int start = 1;
        int end = 1000;

        System.out.println("listing static method from outside the class:");
        for (int i = start; i <= end; ++i) {
            if (ArmstrongNumber.isArmstrongNumber(i)) {
                System.out.print(i + " ");
            } 
        }
        System.out.println();


        // Using non-static method from outside the class
        ArmstrongNumber armstrongNumber = new ArmstrongNumber();
        System.out.println("Using non-static method from outside the class");
        armstrongNumber.display(start, end);
    }
}