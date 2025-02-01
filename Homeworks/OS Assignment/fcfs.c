#include <stdio.h>
#include "fcfs.h"

void fcfs_scheduling(Process processes[], int n) {
    int total_waiting_time=0, total_turnaround_time=0;

    processes[0].waiting_time=0;
    processes[0].turnaround_time = processes[0].burst_time;

    for(int i=1; i<n; i++){

        processes[i].waiting_time=processes[i-1].waiting_time + processes[i-1].burst_time;
        processes[i].turnaround_time=processes[i].waiting_time + processes[i].burst_time;

        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    
    print_results(processes, n, "FCFS");
}
