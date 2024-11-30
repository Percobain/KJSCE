import java.util.Scanner;

public class Exe {
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter a Number: ");
            String input = sc.next();
            boolean isPresent = false;
            for (char c : input.toCharArray()) {
                if (c == '3') {
                    isPresent = true;
                    break;
                }
            }
            if (isPresent) throw new NumException("The number contains digit 3");
            else System.out.println("The number doesnt contain digit 3");
        } catch (Exception e) {
            System.out.println(e.toString());
        }
    }
}
