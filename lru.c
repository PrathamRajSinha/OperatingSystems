#include <stdio.h>
#include <stdbool.h>

int main() {
    int frames, n;
    printf("\nEnter the number of frames: ");
    scanf("%d", &frames);
    printf("Enter the number of pages in the incoming stream: ");
    scanf("%d", &n);

    int incomingStream[n];
    printf("Enter the page reference stream: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &incomingStream[i]);
    }
    int queue[frames];
    int occupied = 0;
    int pagefault = 0;
    printf("Pages:\t");
    for(int i=0; i<frames; i++){
    printf("Frame %d\t",i+1);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d:  \t", incomingStream[i]);
        // Check if incoming page is already in the frames
        bool hit = false;
        for (int j = 0; j < occupied; j++) {
            if (queue[j] == incomingStream[i]) {
                hit = true;
                // Move the hit page to the front (most recently used)
                int temp = queue[j];
                for (int k = j; k > 0; k--) {
                    queue[k] = queue[k - 1];
                }
                queue[0] = temp;
                break;
            }
        }
        if (!hit) {
            if (occupied < frames) {
                // If there's an empty frame, add the page to it
                queue[occupied] = incomingStream[i];
                occupied++;
            } else {
                // Replace the least recently used page
                for (int j = frames - 1; j > 0; j--) {
                    queue[j] = queue[j - 1];
                }
                queue[0] = incomingStream[i];
            }
            pagefault++;
        }
        // Print the frames
        for (int j = 0; j < frames; j++) {
            if (j < occupied) {
                printf("%d\t", queue[j]);
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }
    printf("Page Fault: %d\n", pagefault);
    return 0;
}
