// Experiment 4 - First-Come-First-Server (FCFS) CPU Scheduling Algorithm

#include <stdio.h>

struct process_control_block
{
    int number, arrival_time, burst_time;
    int start_time, waiting_time, completion_time, turn_around_time;
} process[5], temp; // Maximum Processes Allowed = 5

void main()
{
    int n, start_time[10], completion_time[10];
    float total_wt = 0, total_tat = 0;

    printf("Number of Process = ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nProcess Number = ");
        scanf("%d", &process[i].number);

        printf("\tArrival Time = ");
        scanf("%d", &process[i].arrival_time);

        printf("\tBurst Time = ");
        scanf("%d", &process[i].burst_time);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (process[i].arrival_time > process[j].arrival_time)
            {
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    printf("\nProcess Name\tArrival Time\tBurst Time\tStart Time\tCompletion Time\t\tWaiting Time\tTurn Around Time\n");
    for (int i = 0; i < n; i++)
    {
        // if i == 0 -> process[i].start_time = process[i].arrival_time
        // else -> process[i].start_time = process[i - 1].completion_time
        process[i].start_time = (i == 0) ? process[i].arrival_time : process[i - 1].completion_time;

        process[i].completion_time = process[i].start_time + process[i].burst_time;
        process[i].turn_around_time = process[i].completion_time - process[i].arrival_time;
        process[i].waiting_time = process[i].turn_around_time - process[i].burst_time;

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n",
               process[i].number,
               process[i].arrival_time,
               process[i].burst_time,
               process[i].start_time,
               process[i].completion_time,
               process[i].waiting_time,
               process[i].turn_around_time);

        total_wt += process[i].waiting_time;
        total_tat += process[i].turn_around_time;
    }

    printf("\nAverage Waiting Time = %f\n", total_wt / n);
    printf("Average Turn Around Time = %f\n", total_tat / n);
}