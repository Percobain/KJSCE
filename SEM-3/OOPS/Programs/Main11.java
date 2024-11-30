import java.util.Scanner;

class Customer {
    int accountId;
    String name;
    double balance;

    public Customer(int accountId, String name, double balance) {
        this.accountId = accountId;
        this.name = name;
        this.balance = balance;
    }
}

public class Main11 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of customers:");
        int n = scanner.nextInt();
        Customer[] customers = new Customer[n];

        for (int i = 0; i < n; i++) {
            System.out.println("Enter account id, name and balance for customer " + (i + 1));
            int accountId = scanner.nextInt();
            String name = scanner.next();
            double balance = scanner.nextDouble();
            customers[i] = new Customer(accountId, name, balance);
        }

        while (true) {
            System.out.println("1. Add account\n2. Delete account\n3. Display account details\n4. Exit");
            System.out.println("Enter your choice:");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    customers = addAcc(customers, scanner);
                    break;
                case 2:
                    customers = deleteAcc(customers, scanner);
                    break;
                case 3:
                    display(customers);
                    break;
                case 4:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    private static Customer[] addAcc(Customer[] customers, Scanner scanner) {
        System.out.println("Enter account id, name and balance for new customer:");
        int accountId = scanner.nextInt();
        String name = scanner.next();
        double balance = scanner.nextDouble();
        Customer newCustomer = new Customer(accountId, name, balance);
        Customer[] newCustomers = new Customer[customers.length + 1];
        System.arraycopy(customers, 0, newCustomers, 0, customers.length);
        newCustomers[customers.length] = newCustomer;
        return newCustomers;
    }

    private static Customer[] deleteAcc(Customer[] customers, Scanner scanner) {
        System.out.println("Enter account id to delete:");
        int accountId = scanner.nextInt();
        boolean found = false;
        int index = -1;
        for (int i = 0; i < customers.length; i++) {
            if (customers[i].accountId == accountId) {
                found = true;
                index = i;
                break;
            }
        }
        if (found) {
            Customer[] newCustomers = new Customer[customers.length - 1];
            System.arraycopy(customers, 0, newCustomers, 0, index);
            System.arraycopy(customers, index + 1, newCustomers, index, customers.length - index - 1);
            return newCustomers;
        } else {
            System.out.println("Account not found.");
            return customers;
        }
    }

    private static void display(Customer[] customers) {
        for (int i = 0; i < customers.length; i++) {
            System.out.println("Account Id: " + customers[i].accountId + ", Name: " + customers[i].name + ", Balance: " + customers[i].balance);
        }
    }
}