#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival[n], burst[n], remaining[n], waiting[n], turnaround[n], completed = 0, time = 0;
    float total_wait = 0, total_turnaround = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter arrival and burst time for process P%d: ", i + 1);
        scanf("%d %d", &arrival[i], &burst[i]);
        remaining[i] = burst[i];
    }

    printf("\nGantt Chart:\n");

    while (completed != n) {
        int min_index = -1, min_time = 9999;

        for (int i = 0; i < n; i++) {
            if (arrival[i] <= time && remaining[i] > 0 && remaining[i] < min_time) {
                min_time = remaining[i];
                min_index = i;
            }
        }

        if (min_index == -1) {
            time++;
            continue;
        }

        remaining[min_index]--;
        printf("P%d ", min_index + 1);

        if (remaining[min_index] == 0) {
            completed++;
            int finish_time = time + 1;
            turnaround[min_index] = finish_time - arrival[min_index];
            waiting[min_index] = turnaround[min_index] - burst[min_index];
            total_wait += waiting[min_index];
            total_turnaround += turnaround[min_index];
        }

        time++;
    }

    printf("\n\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, arrival[i], burst[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time: %.2f", total_wait / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround / n);

    return 0;
}
