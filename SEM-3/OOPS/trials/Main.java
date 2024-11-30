package trials;

import java.util.Scanner;

public class Main {
    Customer[] customers;
    int n;

    public Main(int n) {
        this.n = n;
        customers = new Customer[n];
    }

    public void addAccount(int accId, String accName, double balance) {
        for (int i = 0; i < n; ++i) {
            if (customers[i] == null) {
                customers[i] = new Customer(accId, accName, balance);
                System.out.println("Account added successfully!");
                break;
            } 
        }
    }

    public void deleteAccount(int accId) {
        for (int i = 0; i < n; ++i) {
            if (customers[i] != null && customers[i].accId == accId) {
                customers[i] = null;
                System.out.println("Account deleted successfully!");
                break;
            }
        }
    }

    public void displayAccount(int accId) {
        for (int i = 0; i < n; ++i) {
            if (customers[i] != null && customers[i].accId == accId) {
                System.out.println("Account ID: " + customers[i].accId);
                System.out.println("Account Name: " + customers[i].accName);
                System.out.println("Balance: " + customers[i].balance);
                System.out.println();
                break;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of accounts: ");
        int n = sc.nextInt();
        Main obj = new Main(n);

        while (true) {
            System.out.println("1. Add Account\n2. Delete Account\n3. Display Account\n4. Exit");
            System.out.print("Enter your choice: ");
            int ch = sc.nextInt();
            switch(ch) {
                case 1:
                    System.out.println("Enter the Account ID: ");
                    int accId = sc.nextInt();
                    System.out.println("Enter the Account Name: ");
                    String accName = sc.next();
                    System.out.println("Enter the Balance: ");
                    double balance = sc.nextDouble();
                    obj.addAccount(accId, accName, balance);
                    break;
                case 2:
                    System.out.println("Enter the Account ID: ");
                    accId = sc.nextInt();
                    obj.deleteAccount(accId);
                    break;
                case 3:
                    System.out.println("Enter the Account ID: ");
                    accId = sc.nextInt();
                    obj.displayAccount(accId);
                    break;
                case 4:
                    sc.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid choice!");
            }
        }
    }
}