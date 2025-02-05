#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
    bool completed;
} Process;

void sort_by_arrival(Process processes[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(processes[j].arrival_time > processes[j+1].arrival_time){
                Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}

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


void sjf_scheduling(Process processes[], int n) {
    sort_by_arrival(processes, n);

    int completed = 0, current_time = 0;

    while(completed < n){
        int shortest_job = -1;
        int min_burst_time = 1e9;

        for(int i=0; i<n; i++){
            if(!processes[i].completed && processes[i].arrival_time <= current_time){
                if(processes[i].burst_time < min_burst_time){
                    min_burst_time = processes[i].burst_time;
                    shortest_job = i;
                }
            }
        }

        if(shortest_job == -1){
            current_time++;
        }
        else{
            int i = shortest_job;
            processes[i].waiting_time = current_time - processes[i].arrival_time;
            processes[i].completion_time = current_time + processes[i].burst_time;
            processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
            processes[i].completed = true;
            completed++;
            current_time = processes[i].completion_time;
        }
    }

    print_results(processes, n, "SJF");
}


int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for(int i=0; i<n; i++){
        processes[i].pid = i+1;
        processes[i].completed = false;
        printf("Enter arrival time and burst time for Process %d: ", i+1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    sjf_scheduling(processes, n);

    return 0;
}
