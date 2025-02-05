#include <stdio.h>

// Define the Process structure
typedef struct {
    int pid;
    int arrival_time; 
    int burst_time;
    int waiting_time;
    int turnaround_time; 
    int completion_time; 
} Process;

void sort_by_arrival(Process processes[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(processes[j].arrival_time > processes[j+1].arrival_time){
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j+1] = temp;
            }
        }
    }
}

void print_results(Process processes[], int n, const char *scheduling_type){
    printf("\n%s Scheduling Results:\n", scheduling_type);
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");

    float total_waiting_time=0, total_turnaround_time=0;
    
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

void fcfs_scheduling(Process processes[], int n){
    sort_by_arrival(processes, n);
    
    int current_time = 0;
    
    for(int i=0; i<n; i++){
        if(current_time < processes[i].arrival_time){
            current_time = processes[i].arrival_time;
        }

        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;

        current_time = processes[i].completion_time;
    }

    print_results(processes, n, "FCFS");
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1; // Assigning process ID
        printf("Enter arrival time and burst time for Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    fcfs_scheduling(processes, n);

    return 0;
}
