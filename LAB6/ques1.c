#include <stdio.h>
#include <stdlib.h>

#define MAX 10


struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
    int priority;
};

void findAverageTime(struct Process proc[], int n);
void sortByArrivalTime(struct Process proc[], int n);
void sortByBurstTime(struct Process proc[], int n);
void sortByPriority(struct Process proc[], int n);


void preemptiveSJF(struct Process proc[], int n) {
    int time = 0;
    int completed = 0;
    int i, minBurstTimeIdx;
    int allProcessesArrived = 0;

    printf("\nPreemptive SJF Scheduling:\n");

    while (completed < n) {
        minBurstTimeIdx = -1;
        int minBurstTime = 9999;
        allProcessesArrived = 1;
        for (i = 0; i < n; i++) {
            if (proc[i].arrivalTime <= time && proc[i].remainingTime > 0) {
                allProcessesArrived = 0;
                if (proc[i].remainingTime < minBurstTime) {
                    minBurstTime = proc[i].remainingTime;
                    minBurstTimeIdx = i;
                }
            }
        }

        if (minBurstTimeIdx != -1) {
             proc[minBurstTimeIdx].remainingTime--;
            time++;
           if (proc[minBurstTimeIdx].remainingTime == 0) {
                completed++;
                proc[minBurstTimeIdx].turnaroundTime = time - proc[minBurstTimeIdx].arrivalTime;
                proc[minBurstTimeIdx].waitingTime = proc[minBurstTimeIdx].turnaroundTime - proc[minBurstTimeIdx].burstTime;
            }
        } else
            if (allProcessesArrived) {

                time++;
            } else {

                time++;
            }
        }
    }

    findAverageTime(proc, n);
}


void roundRobin(struct Process proc[], int n, int timeQuantum) {
    int time = 0;
    int completed = 0;
    int i;
    int remainingProcesses = n;

    printf("\nRound Robin Scheduling (Time Quantum = %d):\n", timeQuantum);

    for (i = 0; i < n; i++) {
        proc[i].remainingTime = proc[i].burstTime;
    }


    while (remainingProcesses > 0) {
        for (i = 0; i < n; i++) {

            if (proc[i].arrivalTime <= time && proc[i].remainingTime > 0) {

                int timeSlice = (proc[i].remainingTime <= timeQuantum) ? proc[i].remainingTime : timeQuantum;


                proc[i].remainingTime -= timeSlice;
                time += timeSlice;

                if (proc[i].remainingTime == 0) {
                    remainingProcesses--;
                    proc[i].turnaroundTime = time - proc[i].arrivalTime;
                    proc[i].waitingTime = proc[i].turnaroundTime - proc[i].burstTime;
                }
            }
        }
    }


    findAverageTime(proc, n);

void priorityScheduling(struct Process proc[], int n) {
    int time = 0;
    int completed = 0;
    int i, j;
    int minPriorityIdx;

    printf("\nNon-preemptive Priority Scheduling:\n");

    for (i = 0; i < n; i++) {
        proc[i].remainingTime = proc[i].burstTime;
    }


    while (completed < n) {
        minPriorityIdx = -1;
        int minPriority = 9999;


        for (i = 0; i < n; i++) {

            if (proc[i].arrivalTime <= time && proc[i].remainingTime > 0) {
                if (proc[i].priority < minPriority) {
                    minPriority = proc[i].priority;
                    minPriorityIdx = i;
                }
            }
        }


        if (minPriorityIdx != -1) {

            time += proc[minPriorityIdx].remainingTime;
            proc[minPriorityIdx].remainingTime = 0;
            completed++;

            proc[minPriorityIdx].turnaroundTime = time - proc[minPriorityIdx].arrivalTime;
            proc[minPriorityIdx].waitingTime = proc[minPriorityIdx].turnaroundTime - proc[minPriorityIdx].burstTime;
        } else {

            time++;
        }
    }


    findAverageTime(proc, n);
}


void findAverageTime(struct Process proc[], int n) {
    int i;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (i = 0; i < n; i++) {
        totalWaitingTime += proc[i].waitingTime;
        totalTurnaroundTime += proc[i].turnaroundTime;
    }

    printf("\nAverage Waiting Time: %.2f", totalWaitingTime / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTurnaroundTime / n);
}


void sortByArrivalTime(struct Process proc[], int n) {
    int i, j;
    struct Process temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (proc[i].arrivalTime > proc[j].arrivalTime) {
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}


void sortByBurstTime(struct Process proc[], int n) {
    int i, j;
    struct Process temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (proc[i].burstTime > proc[j].burstTime) {
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}


void sortByPriority(struct Process proc[], int n) {
    int i, j;
    struct Process temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (proc[i].priority > proc[j].priority) {
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

int main() {
    struct Process proc[MAX];
    int n, timeQuantum, choice;

    printf("Enter the number of processes: ");
    scanf("%d", &n);


    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("\nEnter Arrival Time and Burst Time for Process %d: \n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &proc[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &proc[i].burstTime);
        proc[i].remainingTime = proc[i].burstTime;
    }

    do {
        printf("\nMENU:\n");
        printf("1. Preemptive SJF Scheduling\n");
        printf("2. Round Robin Scheduling\n");
        printf("3. Non-preemptive Priority Scheduling\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                sortByArrivalTime(proc, n);
                preemptiveSJF(proc, n);
                break;
            case 2:
                printf("Enter Time Quantum: ");
                scanf("%d", &timeQuantum);
                sortByArrivalTime(proc, n);
                roundRobin(proc, n, timeQuantum);
                break;
            case 3:
                sortByArrivalTime(proc, n);

                for (int i = 0; i < n; i++) {
                    printf("Priority for Process %d: ", i + 1);
                    scanf("%d", &proc[i].priority);
                }
                sortByPriority(proc, n);
                priorityScheduling(proc, n);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}
