```c
student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_5$ cat q1.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include<sys/wait.h>
int main(){
    int status;
    pid_t p1,p2,p3,p4,pid;
    pid=fork();
    //checking for child thread
    if(pid==0){
        p1=getpid();
        p2=getppid();
        printf("PID of Child Process : %d\n",p1);
        printf("PPID of Child Process : %d\n",p2);}
    //checking for parent thread
    if(pid>0){
        wait(&status);//to ensure child thread terminates before parent starts execution
        p3=getpid();
        p4=getppid();
        printf("PID of Parent Process : %d\n",p3);
        printf("PPID of Parent Process : %d\n",p4);}
    for(int i=1;i<=3;i++){
        sleep(1);
        printf("%d\n",i);}
    return 0;}
student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_5$ cat q2.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include<sys/wait.h>
int main(int argc, char *argv[]){
    int status;
    char **temp_array=argv;
    pid_t fork_return;
    fork_return=fork();
    if(fork_return==0){
        for(int i=0;i<argc;i++){
            for(int j=0;j<argc-i-1;j++){
                if((*temp_array[j])>(*temp_array[j+1])){
                    char *temp=temp_array[j];
                    temp_array[j]=temp_array[j+1];
                    temp_array[j+1]=temp;}}}
        printf("\nSORTED STRINGS : \n");
        for(int i=0;i<argc;i++){
            printf("%s\t",temp_array[i]);}}
    if(fork_return>0){
        wait(&status);
        printf("\nUNSORTED STRINGS : \n");
        for(int i=0;i<argc;i++){
            printf("%s\t",temp_array[i]);}}}
student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_5$ cat q3.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
void bubbleSort(char *arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;}}}}
void selectionSort(char *arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[j], arr[minIndex]) < 0) {
                minIndex = j;}}
        if (minIndex != i) {
            char *temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;}}}
int main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    char **strings = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        strings[i] = (char *)malloc(100 * sizeof(char));  }
    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {scanf("%s", strings[i]);}
    pid_t pid1, pid2;
    pid1 = fork();
    if (pid1 == 0) {
        bubbleSort(strings, n);
        printf("\nBubble Sort result:\n");
        for (int i = 0; i < n; i++) {
            printf("%s\n", strings[i]);}
        exit(0);}
    pid2 = fork();
    if (pid2 == 0) {
        selectionSort(strings, n);
        printf("\nSelection Sort result:\n");
        for (int i = 0; i < n; i++) {
            printf("%s\n", strings[i]);}
        exit(0);}
    waitpid(pid1, NULL, 0);  
    waitpid(pid2, NULL, 0);  
    for (int i = 0; i < n; i++) {
        free(strings[i]);}
    free(strings);
    return 0;
}

```
