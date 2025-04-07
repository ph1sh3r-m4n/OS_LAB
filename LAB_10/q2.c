#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int findIdx(int *frames, int nf, int page) {
    for (int i = 0; i < nf; i++) {
        if (frames[i] == page) {return i;}}
    return -1;}
void LRU(int *pages, int np, int nf) {
    int *frames = (int *)malloc(nf * sizeof(int));
    int *last = (int *)malloc(nf * sizeof(int));
    int pageF = 0, pageH = 0, time = 0;
    for (int i = 0; i < nf; i++) {
        frames[i] = -1;
        last[i] = -1;}
    printf("\nLRU Page Replacement:\n");
    for (int i = 0; i < np; i++) {
        int page = pages[i];
        int index = findIdx(frames, nf, page);
        if (index != -1) {last[index] = time++;} 
        else { 
            pageF++;
            int lru_index = 0;
            for (int j = 1; j < nf; j++) {
                if (last[j] < last[lru_index]) {lru_index = j;}}
            frames[lru_index] = page;
            last[lru_index] = time++;}
        printf("Frames: ");
        for (int j = 0; j < nf; j++) {
            if (frames[j] == -1) printf("_ ");
            else printf("%d ", frames[j]);}
    printf("\n");}
    printf("\nTotal page faults: %d\n", pageF);
    free(frames);
    free(last);}
int main() {
    int nf, np;
    printf("Enter the number of frames: ");
    scanf("%d", &nf);
    printf("Enter the total number of pages: ");
    scanf("%d", &np);
    int *pages = (int *)malloc(np * sizeof(int));
    printf("Enter page sequence: ");
    for (int i = 0; i < np; i++) {scanf("%d", &pages[i]);}
    LRU(pages, np, nf);
    free(pages);
    return 0;}
