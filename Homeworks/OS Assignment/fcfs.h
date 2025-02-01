#ifndef FCFS_H
#define FCFS_H

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
}Process;

void fcfs_scheduling(Process processes[], int n);
void print_results(Process processes[], int n, char *algorithm);

#endif
