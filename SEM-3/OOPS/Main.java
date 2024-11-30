import java.util.Scanner;

public class Main() {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of customers: ");
        int n = sc.nextInt();
        Customer[] customers = new Customer[n];

        for (int i = 0; i < n; ++i) {
            System.out.println("Enter the account id, name & balance: ");
            int accId = sc.nextInt();
            String name = sc.next();
            double bal = sc.nextDouble();
            customers[i] = new Customer(accId, name, bal);
        }

        while (true) {
            System.out.println("\"1. Add account\\n" + //
                                "2. Delete account\\n" + //
                                "3. \r\n" + //
                                "Display account details\\n" + //
                                "4. Exit");
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    customers = addAcc(customers, scanner);
                    break;
            }
        }
    }

    private static Customer[] addAcc(Customer[] customers, Scanner scanner) {
        System.out.println("Enter the account id, name & balance: ");
        int accId = scanner.nextInt();
        String name = scanner.next();
        double bal = scanner.nextDouble();
        Customer newCustomer = new Customer(accId, name, bal);
        Customer[] newCustomers = new Customer[customers.length + 1];
        System.arraycopy(newCustomer, accId, newCustomers, accId, accId);

    }
}