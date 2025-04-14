#include <stdio.h>

typedef struct Process {
    int pid;
    int bt;  
    int priority;
} Process;

void sortProcessesByPriority(Process proc[], int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (proc[j].priority > proc[j+1].priority) {
                Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
}

void findWaitingTime(Process proc[], int n, int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < n; ++i) {
        wt[i] = wt[i-1] + proc[i-1].bt;
    }
}

void printResults(Process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    
    findWaitingTime(proc, n, wt);
    for (int i = 0; i < n; i++) {
        tat[i] = proc[i].bt + wt[i];
    }

    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].priority, proc[i].bt, wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage waiting time = %.2f\n", (float)total_wt / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    Process proc[n];
    
    printf("Enter Process ID, Priority, and Burst Time:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &proc[i].pid, &proc[i].priority, &proc[i].bt);
    }
    
    sortProcessesByPriority(proc, n);
    printResults(proc, n);
    
    return 0;
}