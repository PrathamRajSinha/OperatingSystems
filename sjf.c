/*
#include <stdio.h>

int main() {
    printf("Pratham Raj Sinha 21BIT0092\n\n");
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n]; 
    int wt[n]; 
    int ct[n];
    int tat[n];
    int i=0;  
    int at[n];
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time of process %d: ", i+1 );
        scanf("%d", &at[i]);
        printf("Enter burst time of process %d: ", i+1 );
        scanf("%d", &bt[i]);
        
         }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                int temp1 = at[j];
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
                at[j] = at[j+1];
                at[j+1] = temp1;
            }
        }
    }

    printf("Processes in shortest burst time order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", bt[i]);
    }
    printf("\n");
    printf("\n");
    for (int i=1; i<n+1; i++){
        wt[0]=0;
        wt[i] = bt[i-1]+wt[i-1];
        printf("Wait time for process %d is : %d\n",i,wt[i-1]);
    }
    printf("\n");
    for (int i=0; i<n; i++){
    ct[i] = at[i]+ct[i-1]+ bt[i];
        printf("Completion time of process %d: %d\n",i+1,ct[i]);
    }

    int total_tat = 0;
    int total_wt = 0;
    for (int i = 0; i < n; i++){
        tat[i] = at[i]+ bt[i]+wt[i];
        total_tat += at[i]+tat[i];
        total_wt += at[i]+wt[i];
        printf("Turnaround time of process %d is: %d\n", i , tat[i]);
        }
            printf("\n");
    float avg_tat = total_tat/n;
    float avgwt = total_wt/n;
    printf("Average Waiting Time: %.2f\n", avgwt);
    printf("Average turn around time: %.2f\n",avg_tat);
    printf("Process\tAT\tBT\tWT\tCT\tTAT\n");
        for (int i = 0; i < n; i++){
            printf("P[%d]\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],wt[i],ct[i],tat[i]);
        }

}
*/
#include <stdio.h>

int main() {
    printf("Pratham Raj Sinha 21BIT0092\n\n");
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n]; 
    int wt[n]; 
    int ct[n];
    int tat[n];
    int i=0;  
    int at[n];
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time of process %d: ", i+1 );
        scanf("%d", &at[i]);
        printf("Enter burst time of process %d: ", i+1 );
        scanf("%d", &bt[i]);
    }
    
    // Sort the processes based on arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int temp1 = at[j];
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
                at[j] = at[j+1];
                at[j+1] = temp1;
            }
        }
    }

    printf("Processes in shortest burst time order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", bt[i]);
    }
    printf("\n\n");

    wt[0] = 0;
    ct[0] = at[0] + bt[0];
    tat[0] = ct[0] - at[0];

    for (int i = 1; i < n; i++) {
        // Calculate waiting time
        wt[i] = ct[i - 1] - at[i];
        if (wt[i] < 0)
            wt[i] = 0;

        // Calculate completion time
        ct[i] = at[i] + wt[i] + bt[i];

        // Calculate turnaround time
        tat[i] = ct[i] - at[i];
    }

    int total_tat = 0;
    int total_wt = 0;

    printf("Process\tAT\tBT\tWT\tCT\tTAT\n");
    for (int i = 0; i < n; i++) {
        total_tat += tat[i];
        total_wt += wt[i];
        printf("P[%d]\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], ct[i], tat[i]);
    }

    float avg_tat = (float)total_tat / n;
    float avg_wt = (float)total_wt / n;

    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}
