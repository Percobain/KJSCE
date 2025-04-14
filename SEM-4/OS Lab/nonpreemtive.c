#include <stdio.h>
#include <stdbool.h>

struct Process {
    int id;
    int aT;
    int bT;
    int wT;
    int TAT;
    bool completed;
};

void FCFS(struct Process processes[], int n) {
    int cT = 0;
    float tWT = 0, tTAT = 0;
    printf("FCFS Scheduling\n");
    printf("Process\t\tAT\t\tBT\t\tWT\t\tTAT\n");

    for (int i = 0; i < n; ++i) {
        if (processes[i].aT > cT) {
            cT = processes[i].aT;
        }

        processes[i].wT = cT - processes[i].aT;
        processes[i].TAT = processes[i].wT + processes[i].bT;
        
        tWT += processes[i].wT;
        tTAT += processes[i].TAT;

        cT += processes[i].bT;

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].aT, processes[i].bT, processes[i].wT, processes[i].TAT);
    }
    printf("Average WT: %.2f\n", tWT / n);
    printf("Average TAT: %.2f\n", tTAT / n);
}

void SJF(struct Process processes[], int n) {
    int cT = 0;
    float tWT = 0, tTAT = 0;
    int completed = 0;
    int sji;
    
    printf("SJF Scheduling:\n");
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    while (completed != n) {
        sji = -1;
        int shortestBurstTime = 9999;

        for (int i = 0; i < n; ++i) {
            if (processes[i].aT <= cT && !processes[i].completed && processes[i].bT < shortestBurstTime) {
                shortestBurstTime = processes[i].bT;
                sji = i;
            }
        }

        if (sji == -1) {
            cT++;
            continue;
        }

        processes[sji].wT = cT - processes[sji].aT;
        processes[sji].TAT = processes[sji].wT + processes[sji].bT;

        tWT += processes[sji].wT;
        tTAT += processes[sji].TAT;

        cT += processes[sji].bT;
        processes[sji].completed = true;
        completed++;

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[sji].id, processes[sji].aT, processes[sji].bT, processes[sji].wT, processes[sji].TAT);
    }
    printf("Average WT: %.2f\n", tWT / n);
    printf("Average TAT: %.2f\n", tTAT / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        printf("Enter Arrival Time and Burst Time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].aT, &processes[i].bT);
        processes[i].wT = 0;
        processes[i].TAT = 0;
        processes[i].completed = false;
    }

    FCFS(processes, n);

    for (int i = 0; i < n; i++) {
        processes[i].wT = 0;
        processes[i].TAT = 0;
        processes[i].completed = false;
    }

    SJF(processes, n);

    return 0;
}