#include <stdio.h>

void calculateWaitingTime(int at[], int bt[], int N) {
    int wt[N];
    wt[0] = 0;

    printf("P.No.\tArrival Time\tBurst Time\tWaiting Time\n");
    printf("1\t\t%d\t\t%d\t\t%d\n", at[0], bt[0], wt[0]);

    for (int i = 1; i < N; ++i) {
        wt[i] = (at[i-1] + bt[i-1] + wt[i-1]) - at[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, at[i], bt[i], wt[i]);
    }

    float sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += wt[i];
    }

    float average = sum / N;
    printf("Average waiting time = %.2f\n", average);
}

int main() {
    int N = 5;
    int at[] = {0, 1, 2, 3};    // Arrival times
    int bt[] = {5, 3, 8, 6};    // Burst times

    calculateWaitingTime(at, bt, N);
    return 0;
}