#include <stdio.h>
#include <stdlib.h>

#define DIRECTION_LEFT -1
#define DIRECTION_RIGHT 1

int main() {
    printf("Pratham Raj Sinha 21BIT0092\n");

    int n, head, i, seek_time = 0;
    int max_memory;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int *requests = (int *)malloc(n * sizeof(int));

    printf("Enter the disk requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    int direction;
    printf("Enter the direction (left = -1, right = 1): ");
    scanf("%d", &direction);

    printf("Enter the maximum memory size: ");
    scanf("%d", &max_memory);

    // Sort the requests in ascending order
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    int initialIndex = 0;
    for (i = 0; i < n; i++) {
        if (requests[i] >= head) {
            initialIndex = i;
            break;
        }
    }

    // Scan in the specified direction
    if (direction == DIRECTION_LEFT) {
        // Scan to the left
        for (i = initialIndex - 1; i >= 0; i--) {
            seek_time += abs(head - requests[i]);
            head = requests[i];
        }

        // Scan to the right
        seek_time += abs(head - 0);
        head = 0;

        for (i = initialIndex; i < n; i++) {
            seek_time += abs(head - requests[i]);
            head = requests[i];
        }
    } else if (direction == DIRECTION_RIGHT) {
        // Scan to the right
        for (i = initialIndex; i < n; i++) {
            seek_time += abs(head - requests[i]);
            head = requests[i];
        }

        // Scan to the left
        seek_time += abs(head - max_memory);
        head = max_memory;

        for (i = initialIndex - 1; i >= 0; i--) {
            seek_time += abs(head - requests[i]);
            head = requests[i];
        }
    }

    printf("Total seek time: %d\n", seek_time);

    free(requests);

    return 0;
}
