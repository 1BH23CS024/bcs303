// Experiment 4 - First-Come-First-Server (FCFS) CPU Scheduling Algorithm

#include <stdio.h>

struct process_control_block
{
    int process_num, arrival_time, burst_time;
    int completion_time, start_time, turn_around_time, waiting_time;
} pcb[5] = {0}; // Maximum Processes Allowed = 5

void main()
{
    int i, n;
    int start_time[10], completion_time[10];
    float total_wt = 0, total_tat = 0;

    printf("Number of Process = ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nProcess Number = ");
        scanf("%d", &pcb[i].process_num);

        printf("\tArrival Time = ");
        scanf("%d", &pcb[i].arrival_time);

        printf("\tBurst Time = ");
        scanf("%d", &pcb[i].burst_time);
    }

    printf("\nProcess Name\tArrival Time\tBurst Time\tStart Time\tCompletion Time\t\tWaiting Time\tTurn Around Time\n");
    for (i = 0; i < n; i++)
    {
        if (i == 0)
            pcb[i].start_time = pcb[i].arrival_time;
        else
            pcb[i].start_time = pcb[i - 1].completion_time;

        pcb[i].waiting_time = pcb[i].start_time - pcb[i].arrival_time;          // Waiting Time = Start Time - Arrival Time
        pcb[i].completion_time = pcb[i].start_time + pcb[i].burst_time;         // Completion Time = Start Time + Burst Time
        pcb[i].turn_around_time = pcb[i].completion_time - pcb[i].arrival_time; // Turn Around Time = Completion Time - Arrival Time

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n",
               pcb[i].process_num,
               pcb[i].arrival_time,
               pcb[i].burst_time,
               pcb[i].start_time,
               pcb[i].completion_time,
               pcb[i].waiting_time,
               pcb[i].turn_around_time);

        total_wt += pcb[i].waiting_time;
        total_tat += pcb[i].turn_around_time;
    }

    printf("\nAverage Waiting Time = %f\n", total_wt / n);
    printf("Average Turn Around Time = %f\n", total_tat / n);
}