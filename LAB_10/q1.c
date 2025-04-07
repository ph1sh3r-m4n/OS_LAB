#include <stdio.h>
#include <stdlib.h>
void fifo(int *p, int np, int nf) {
    int *frames = (int *)malloc(nf * sizeof(int));
    int *visited = (int *)malloc(nf * sizeof(int));
    int pageF = 0, pointer = 0;
    for (int i = 0; i < nf; i++) {
        frames[i] = -1;
        visited[i] = 0;}
    for (int i = 0; i < np; i++) {
        int page = p[i];
        int found = 0;
        for (int j = 0; j < nf; j++) {
            if (frames[j] == page) {
                found = 1;
                break;}}
        if (!found) {
            frames[pointer] = page;
            pointer = (pointer + 1) % nf;
            pageF++;}
        printf("Frames: ");
        for (int j = 0; j < nf; j++) {
            if (frames[j] == -1)
                printf("_ ");
            else
                printf("%d ", frames[j]);}
        printf("\n");}
    printf("Total page faults (FIFO): %d\n", pageF);
    free(frames);
    free(visited);}
void optimal(int *p, int np, int nf) {
    int *frames = (int *)malloc(nf * sizeof(int));
    int pageF = 0;
    for (int i = 0; i < nf; i++) {frames[i] = -1;}
    for (int i = 0; i < np; i++) {
        int page = p[i];
        int found = 0;
        for (int j = 0; j < nf; j++) {
            if (frames[j] == page) {
                found = 1;
                break;}}
        if (!found) {
            if (i < nf) {frames[i] = page;} 
            else {
                int far = -1;
                int repIdx = -1;
                for (int j = 0; j < nf; j++) {
                    int k;
                    for (k = i + 1; k < np; k++) {
                        if (p[k] == frames[j]) {
                            break;}}
                    if (k == np) {
                        repIdx = j;
                        break;} 
                    else if (k > far) {
                        far = k;
                        repIdx = j;}}
                frames[repIdx] = page;}
            pageF++;}
        printf("Frames: ");
        for (int j = 0; j < nf; j++) {
            if (frames[j] == -1) printf("_ ");
            else printf("%d ", frames[j]);}
        printf("\n");}
    printf("Total page faults (Optimal): %d\n", pageF);
    free(frames);}
int main() {
    int nf, np;
    printf("Enter number of frames: ");
    scanf("%d", &nf);
    printf("Enter number of pages: ");
    scanf("%d", &np);
    int *p = (int *)malloc(np * sizeof(int));
    printf("Enter the page reference string: ");
    for (int i = 0; i < np; i++) {scanf("%d", &p[i]);}
    printf("\nFIFO Page Replacement Algorithm:\n");
    fifo(p, np, nf);
    printf("\nOptimal Page Replacement Algorithm:\n");
    optimal(p, np, nf);
    free(p);
    return 0;}
