#include <stdio.h>
#include <stdlib.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    printf("\nFirst Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d is allocated to Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d is not allocated\n", i + 1);
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
    printf("\nBest Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d is allocated to Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d is not allocated\n", i + 1);
    }
}

int main() {
    int m, n;

    printf("Enter the number of blocks: ");
    scanf("%d", &m);
    int *blockSize = (int *)malloc(m * sizeof(int));
    printf("Enter the size of each block:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int *processSize = (int *)malloc(n * sizeof(int));
    printf("Enter the size of each process:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &processSize[i]);

    int *blockSizeCopy = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        blockSizeCopy[i] = blockSize[i];

    firstFit(blockSize, m, processSize, n);

    for (int i = 0; i < m; i++)
        blockSize[i] = blockSizeCopy[i];

    bestFit(blockSize, m, processSize, n);

    free(blockSize);
    free(processSize);
    free(blockSizeCopy);

    return 0;
}

