#include <stdio.h>
#include "fcfs.h"
#include "modified_scheduling.h"

int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    printf("Enter process details (PID, Arrival Time, Burst Time):\n");
    for(int i=0; i<n; i++) {
        scanf("%d %d %d", &processes[i].pid, &processes[i].arrival_time, &processes[i].burst_time);
    }

    fcfs_scheduling(processes, n);

    sjf_scheduling(processes, n);

    return 0;
}
