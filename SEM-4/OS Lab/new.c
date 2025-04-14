#include <stdio.h>

typedef struct Process {
    int pid;
    int bt;  
    int priority;
}Process;

void sortProcessesByPriority(Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].priority > proc[j + 1].priority) {
                Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
}

void findWaitingTime(Process proc[], int n, int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + proc[i - 1].bt;
    }
}


void printResults(Process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    
    findWaitingTime(proc, n, wt);
    findTurnaroundTime(proc, n, wt, tat);

    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].priority, proc[i].bt, wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);
}


int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    Process proc[n];
    
    printf("Enter Process ID, Priority , and Burst Time:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &proc[i].pid, &proc[i].priority, &proc[i].bt);
    }
}




// Process Burst Time Prirority
// P1 10 3
// P2 1 1
// P3 2 4
// P4 1 5
// P5 5 2


// Process Priority Burst Time Waiting Time Turnaround Time
// Calculations


// AIM: To implement Priority Scheduling Algorithm
// Steps: 
// 1. Create a structure Process with the following fields:
//     - pid: Process ID
//     - bt: Burst Time
//     - priority: Priority

// 2. Create a function sortProcessesByPriority() that sorts the processes based on their priority.
// 3. Create a function findWaitingTime() that calculates the waiting time for each process.
// 5. Create a function printResults() that prints the results of the scheduling algorithm.
// 6. In the main() function, take the number of processes as input from the user.