import java.util.Scanner;
import java.util.Vector;

class Employee implements Comparable<Employee> {
    private String eName;
    private int eId;
    private double eSalary;

    public Employee(String eName, int eId, double eSalary) {
        this.eName = eName;
        this.eId = eId;
        this.eSalary = eSalary;
    }
    public String getEName() {
        return eName;
    }

    public int getEId() {
        return eId;
    }

    public double getESalary() {
        return eSalary;
    }

    @Override
    public int compareTo(Employee other) {
        return Double.compare(this.eSalary, other.eSalary);
    }

    @Override
    public String toString() {
        return "Employee Name: " + eName + ", ID: " + eId + ", Salary: " + eSalary;
    }
}

class EmployeeVector {
    private Vector<Employee> employees;

    public EmployeeVector() {
        employees = new Vector<>();
    }

    public void create(Employee[] employeeArray) {
        for (Employee e : employeeArray) {
            insert(e);
        }
    }

    public void insert(Employee e) {
        int index = 0;
        while (index < employees.size() && employees.get(index).compareTo(e) < 0) {
            index++;
        }
        employees.add(index, e);
    }

    public void deleteByEName(String name) {
        boolean removed = false;
        for (int i = 0; i < employees.size(); i++) {
            if (employees.get(i).getEName().equals(name)) {
                employees.remove(i);
                removed = true;
                System.out.println("Employee with name " + name + " deleted.");
                break;
            }
        }
        if (!removed) {
            System.out.println("Employee with name " + name + " not found.");
        }
    }

    public void deleteByEId(int id) {
        boolean removed = false;
        for (int i = 0; i < employees.size(); i++) {
            if (employees.get(i).getEId() == id) {
                employees.remove(i);
                removed = true;
                System.out.println("Employee with ID " + id + " deleted.");
                break;
            }
        }
        if (!removed) {
            System.out.println("Employee with ID " + id + " not found.");
        }
    }

    public void printEmployees() {
        for (Employee e : employees) {
            System.out.println(e);
        }
    }
}

public class Main12 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        EmployeeVector employeeVector = new EmployeeVector();
        int choice;

        do {
            System.out.println("\nMenu:");
            System.out.println("1. Add Employees");
            System.out.println("2. Insert Employee");
            System.out.println("3. Display All Employees");
            System.out.println("4. Delete Employee by Name");
            System.out.println("5. Delete Employee by ID");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter the number of employees: ");
                    int n = scanner.nextInt();
                    Employee[] employeeArray = new Employee[n];

                    for (int i = 0; i < n; i++) {
                        System.out.println("Enter details for Employee " + (i + 1) + ":");
                        System.out.print("Name: ");
                        String name = scanner.next();
                        System.out.print("ID: ");
                        int id = scanner.nextInt();
                        System.out.print("Salary: ");
                        double salary = scanner.nextDouble();

                        employeeArray[i] = new Employee(name, id, salary);
                    }

                    employeeVector.create(employeeArray);
                    System.out.println("Employees added and sorted by salary.");
                    break;

                case 2:
                    System.out.println("Enter details for the new Employee:");
                    System.out.print("Name: ");
                    String name = scanner.next();
                    System.out.print("ID: ");
                    int id = scanner.nextInt();
                    System.out.print("Salary: ");
                    double salary = scanner.nextDouble();

                    Employee newEmployee = new Employee(name, id, salary);
                    employeeVector.insert(newEmployee);
                    System.out.println("Employee inserted in sorted order.");
                    break;

                case 3:
                    System.out.println("Employees sorted by salary:");
                    employeeVector.printEmployees();
                    break;

                case 4:
                    System.out.print("Enter the name of the employee to delete: ");
                    String nameToDelete = scanner.next();
                    employeeVector.deleteByEName(nameToDelete);
                    break;

                case 5:
                    System.out.print("Enter the ID of the employee to delete: ");
                    int idToDelete = scanner.nextInt();
                    employeeVector.deleteByEId(idToDelete);
                    break;

                case 6:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice. Please try again.");
                    break;
            }
        } while (choice != 6);

        scanner.close();
    }
}
