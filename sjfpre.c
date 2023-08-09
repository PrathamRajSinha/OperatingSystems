#include <stdio.h>
int main()
{
    int at[5] = {3, 1, 4, 0, 2};
    int bt[5] = {1, 4, 2, 6, 3};
    int rt[5] = {1, 4, 2, 6, 3};
    int remain = 0;
    int smallest = -1; // Initialize to an invalid index to handle the first iteration.
    int ct = 0;
    int tat_sum = 0, wt_sum = 0; // Variables to store the sum of TAT and WT
    printf("Pid\tAT\tBT\tCT\tTAT\tWT\n");
    for (int time = 0; remain < 5; time++)
    {
        smallest = -1; // Reset to an invalid index for each time step.
        for (int i = 0; i < 5; i++)
        {
            if (at[i] <= time && rt[i] > 0)
            {
                if (smallest == -1 || rt[i] < rt[smallest])
                {
                    smallest = i;
                }
            }
        }
        rt[smallest]--;
        if (rt[smallest] == 0)
        {
            remain++;
            ct = time + 1;
            int tat = ct - at[smallest];
            int wt = tat - bt[smallest];
            tat_sum += tat;
            wt_sum += wt;
            printf("%d \t %d \t %d \t %d \t %d \t %d \t\n", smallest + 1, at[smallest], bt[smallest], ct, tat, wt);
        }
    }
    // Calculate the averages
    float avg_tat = (float)tat_sum / 5;
    float avg_wt = (float)wt_sum / 5;

    printf("\nAverage TAT: %.2f\n", avg_tat);
    printf("Average WT: %.2f\n", avg_wt);
    return 0;
}