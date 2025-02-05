#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
} Process;

void print_results(Process processes[], int n, const char *scheduling_type){
    printf("\n%s Scheduling Results:\n", scheduling_type);
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");

    float total_waiting_time = 0, total_turnaround_time = 0;

    for(int i=0; i<n; i++){
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].pid, 
               processes[i].arrival_time, 
               processes[i].burst_time, 
               processes[i].waiting_time, 
               processes[i].turnaround_time, 
               processes[i].completion_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

void srtf_scheduling(Process processes[], int n){
    int current_time = 0, completed = 0, min_remaining_time;
    int shortest = -1;
    
    for(int i=0; i<n; i++){
        processes[i].remaining_time = processes[i].burst_time;
    }

    while(completed<n){
        min_remaining_time = 1e9;
        shortest= -1;

        for(int i=0; i<n; i++){
            if(processes[i].arrival_time <= current_time && processes[i].remaining_time>0){
                if(processes[i].remaining_time < min_remaining_time){
                    min_remaining_time = processes[i].remaining_time;
                    shortest = i;
                }
            }
        }

        if(shortest == -1){
            current_time++;
            continue;
        }

        processes[shortest].remaining_time--;

        if(processes[shortest].remaining_time==0){
            completed++;
            processes[shortest].completion_time = current_time + 1;
            processes[shortest].turnaround_time = processes[shortest].completion_time - processes[shortest].arrival_time;
            processes[shortest].waiting_time = processes[shortest].turnaround_time - processes[shortest].burst_time;
        }

        current_time++;
    }

    print_results(processes, n, "SRTF");
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for(int i=0; i<n; i++){
        processes[i].pid = i + 1;
        printf("Enter arrival time and burst time for Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    srtf_scheduling(processes, n);

    return 0;
}
