#include <stdio.h>
#include "modified_scheduling.h"
#include "fcfs.h"

// Sort processes by burst time (SJF)
void sort_by_burst_time(Process processes[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(processes[j].burst_time > processes[j+1].burst_time){
                Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}

void sjf_scheduling(Process processes[], int n){
    sort_by_burst_time(processes, n);

    processes[0].waiting_time=0;
    processes[0].turnaround_time = processes[0].burst_time;

    for(int i=1; i<n; i++){
        processes[i].waiting_time = processes[i-1].waiting_time + processes[i-1].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
    
    print_results(processes, n, "SJF (Modified)");
}
