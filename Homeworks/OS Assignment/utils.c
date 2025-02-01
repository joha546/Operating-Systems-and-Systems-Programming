#include <stdio.h>
#include "fcfs.h"

void print_results(Process processes[], int n, char *algorithm) {
    float total_waiting_time = 0, total_turnaround_time = 0, total_burst_time = 0;
    int total_completion_time = processes[n - 1].turnaround_time; // Last process' completion time

    printf("\n%s Scheduling Results:\n", algorithm);
    printf("PID\tArrival\tBurst\tWaiting\tTurnaround\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrival_time,
               processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
        
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        total_burst_time += processes[i].burst_time;
    }

    float avg_waiting_time = total_waiting_time / n;
    float avg_turnaround_time = total_turnaround_time / n;
    float cpu_utilization = (total_burst_time / total_completion_time) * 100;

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("CPU Utilization: %.2f%%\n", cpu_utilization);
}
