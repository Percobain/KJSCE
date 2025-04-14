#include <stdio.h>

void calculateTimes(int at[], int bt[], int N) {
    int wt[N], tat[N];
    wt[0] = 0;
    tat[0] = bt[0];

    printf("P.No.\tArrival Time\tBurst Time\tWaiting Time\tTurn around Time\n");
    printf("1\t\t%d\t\t%d\t\t%d\t\t%d\n", at[0], bt[0], wt[0], tat[0]);

    float wt_sum = 0, tat_sum = 0;
    wt_sum += wt[0];
    tat_sum += tat[0];

    for (int i = 1; i < N; ++i) {
        wt[i] = (at[i-1] + bt[i-1] + wt[i-1]) - at[i];
        tat[i] = wt[i] + bt[i];
        
        wt_sum += wt[i];
        tat_sum += tat[i];

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
    }

    float wt_avg = wt_sum / N;
    float tat_avg = tat_sum / N;
    
    printf("\nAverage waiting time = %.2f\n", wt_avg);
    printf("Average turnaround time = %.2f\n", tat_avg);
}

int main() {
    int N = 4;
    int at[] = {0, 1, 2, 3};    // Arrival times
    int bt[] = {5, 3, 8, 6};    // Burst times

    calculateTimes(at, bt, N);
    return 0;
}








// 
// WT[0] = 0 
// TAT[0] = BT[0] = 5

// WT[1] = (A[0] + BT[0] + WT[0]) - A[1] = 0 + 5 + 0 - 1 = 4
// TAT[1] = WT[1] + BT[1] = 4 + 3 = 7