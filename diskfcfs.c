#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

int main() {
    int n, head, i, seek_time = 0;
    int requests[MAX_REQUESTS];
    printf("Pratham Raj Sinha 21BIT0092\n");
    
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    
    printf("Enter the disk requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    
    // Calculate total seek time
    for (i = 0; i < n; i++) {
        seek_time += abs(head - requests[i]);
        head = requests[i];
    }
    
    printf("Total seek time: %d\n", seek_time);
    
    return 0;
}
