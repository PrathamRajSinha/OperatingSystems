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

int findLFUPage(int frames[], int counts[], int size) {
    int minCount = counts[0];
    int index = 0;

    for (int i = 1; i < size; i++) {
        if (counts[i] < minCount) {
            minCount = counts[i];
            index = i;
        }
    }

    return index;
}

void LFUPageReplacement(int pages[], int numPages) {
    int frames[MAX_FRAMES];
    int counts[MAX_FRAMES];
    int pageFaults = 0;

    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
        counts[i] = 0;
    }

    printf("Page\tFrames\tPage Faults\n");

    for (int i = 0; i < numPages; i++) {
        int page = pages[i];
        printf("%d\t", page);
        printFrames(frames, MAX_FRAMES);

        if (isPageFault(frames, MAX_FRAMES, page)) {
            pageFaults++;

            int emptyIndex = -1;
            for (int j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] == -1) {
                    emptyIndex = j;
                    break;
                }
            }

            if (emptyIndex != -1) {
                frames[emptyIndex] = page;
                counts[emptyIndex] = 1;
            } else {
                int index = findLFUPage(frames, counts, MAX_FRAMES);
                frames[index] = page;
                counts[index] = 1;
            }
        } else {
            for (int j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] == page) {
                    counts[j]++;
                    break;
                }
            }
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

    LFUPageReplacement(pages, numPages);

    return 0;
}
