package trials;

import java.util.Scanner;

public class PlayerStats {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of Players: ");
        int n = sc.nextInt();
        int runs[][] = new int[n][];
        int mp[] = new int[n];

        for (int i = 0; i < n; ++i) {
            System.out.println("Enter the number of matches played by Player " + (i + 1) + ": ");
            int x = sc.nextInt();
            mp[i] = x;
            runs[i] = new int[x];

            for (int j = 0; j < x; ++j) {
                System.out.println("Enter the runs scored in match " + (j + 1) + "by player " + (i + 1) + ": ");
                runs[i][j] = sc.nextInt();
            }
        }

        System.out.println("\nPlayer Stats: ");
        for (int i = 0; i < n; ++i) {
            System.out.println("Player " + (i + 1) + "Scores: ");
            int totRuns = 0;

            for (int j = 0; j < mp[i]; ++j) {
                System.out.print(runs[i][j] + " ");
                totRuns += runs[i][j];
            }

            double avg = (double) totRuns / mp[i];
            System.out.println("\nTotal Runs: " + totRuns);
            System.out.println("Average: " + avg);
            sc.close();
        }
    }
}
