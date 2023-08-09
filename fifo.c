#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10

void printFrames(int frames[], int size) {
    for (int i = 0; i < size; i++) {
        if (frames[i] == -1)
            printf("- ");
        else
            printf("%d ", frames[i]);
    }
    printf("\n");
}

int isPageFault(int frames[], int size, int page) {
    for (int i = 0; i < size; i++) {
        if (frames[i] == page)
            return 0;
    }
    return 1;
}

void FIFOPageReplacement(int pages[], int numPages) {
    int frames[MAX_FRAMES];
    int frameIndex = 0;
    int pageFaults = 0;

    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    printf("Page\tFrames\tPage Faults\n");

    for (int i = 0; i < numPages; i++) {
        int page = pages[i];
        printf("%d\t", page);
        printFrames(frames, MAX_FRAMES);

        if (isPageFault(frames, MAX_FRAMES, page)) {
            pageFaults++;
            frames[frameIndex] = page;
            frameIndex = (frameIndex + 1) % MAX_FRAMES;
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    printf("Pratham Raj Sinha 21BIT0092\n");
    int pages[MAX_PAGES];
    int numPages;

    printf("Enter the number of pages (up to %d): ", MAX_PAGES);
    scanf("%d", &numPages);

    printf("Enter the page reference string: ");
    for (int i = 0; i < numPages; i++) {
        scanf("%d", &pages[i]);
    }

    FIFOPageReplacement(pages, numPages);

    return 0;
}