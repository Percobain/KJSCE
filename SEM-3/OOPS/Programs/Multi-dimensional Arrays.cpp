#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cout << "Enter the number of players: ";
    cin >> n;

    vector<vector<int>> players(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cout << "Enter the number of matches played by player " << i + 1 << ": ";
        cin >> m;
        players[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cout << "Enter the runs scored in match " << j + 1 << " by player " << i + 1 << ": ";
            cin >> players[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        int totRuns = 0;
        for (int j = 0; j < players[i].size(); ++j) {
            totRuns += players[i][j];
        }
        double avg = (double)totRuns / players[i].size();
        cout << "Player " << i + 1 << " " << "scored " << totRuns << " " << "runs in " << players[i].size() << " " << "matches with an average of " << avg << " " << '\n';
    }

    for (int i = 0; i < n; ++i) {
        players[i].clear();
    }
    players.clear();
}



import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of players: ");
        int n = scanner.nextInt();

        int[][] players = new int[n][];

        for (int i = 0; i < n; ++i) {
            System.out.print("Enter the number of matches played by player " + (i + 1) + ": ");
            int m = scanner.nextInt();
            players[i] = new int[m];
            for (int j = 0; j < m; ++j) {
                System.out.print("Enter the runs scored in match " + (j + 1) + " by player " + (i + 1) + ": ");
                players[i][j] = scanner.nextInt();
            }
        }

        for (int i = 0; i < n; ++i) {
            int totRuns = 0;
            for (int j = 0; j < players[i].length; ++j) {
                totRuns += players[i][j];
            }
            double avg = (double)totRuns / players[i].length;
            System.out.println("Player " + (i + 1) + " scored " + totRuns + " runs in " + players[i].length + " matches with an average of " + avg);
        }
    }
}

