#include <stdio.h>

int main()
{
    int at[10], at2[10], bt[100], ex[100], seq[100], re[100], wt[100], tat[100];
    int n, i, j, start, pos, max = 0, min, idle = 0, k = 0;
    float avg_tat = 0, avg_wt = 0;

    printf("Pratham Raj Sinha 21BIT0092\n\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time for process %d: ",i+1);
        scanf("%d", &at[i]);
        at2[i] = at[i];
        printf("Enter burst time for process %d: ",i+1);
        scanf("%d", &bt[i]);
    }

    start = at[0];
    for (i = 1; i < n; i++)
    {
        if (start > at[i])
        {
            start = at[i];
        }
    }

    printf("Gantt Chart : ");
    for (i = 0; i < n; i++)
    {
        if (max < at[i])
        {
            max = at[i];
        }
    }
    max = max + 1;
    for (i = 0; i < n; i++, k++)
    {
        min = max;
        for (j = 0; j < n; j++)
        {
            if (at[j] != -1)
            {
                if (at[j] < min)
                {
                    min = at[j];
                    pos = j;
                }
            }
        }
        printf("[P%d] ", pos);
        seq[k] = pos;
        if (start < at[pos])
        {
            re[pos] = start;
            idle += at[pos] - start;
            start = at[pos];
            start += bt[pos];
            at[pos] = -1;
            ex[pos] = start;
        }
        else
        {
            re[pos] = start;
            start += bt[pos];
            at[pos] = -1;
            ex[pos] = start;
        }
    }
    printf("\n");

    for (i = 0; i < n; i++)
    {
        tat[i] = ex[i] - at2[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("Process\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("P[%d]\t%d\t%d\t%d\t%d\n", i, at2[i], bt[i], wt[i], tat[i]);
    }

    for (i = 0; i < n; i++)
    {
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("Average waiting time(s): %.2f\n", avg_wt / n);
    printf("Average turnaround time(s): %.2f\n", avg_tat / n);
    printf("CPU idle time(s): %d\n", idle);

    return 0;
}
