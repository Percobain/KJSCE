import java.util.Scanner;
public class Main13 {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter a Number: ");
            String input = scanner.next();
            boolean isPresent = false;
            for (char c : input.toCharArray()) {
                if (c == '3') {
                    isPresent = true;
                    break;
                }
            }
            if (isPresent) {
                throw new NumberException("The Number contains digit 3");
            }
            else {
                System.out.println("The Number does not contain digit 3");
            }
        }
        catch (NumberException e) {
            System.out.println(e.toString());
        }
    }
}