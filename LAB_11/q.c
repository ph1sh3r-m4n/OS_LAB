#include <stdio.h>
#include <stdlib.h>
void sort(int queue[],int n)
{  
   int temp;
   for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(queue[j]>queue[j+1]){
                temp=queue[j];
                queue[j]=queue[j+1];
                queue[j+1]=temp;
            }
        }
    }
}

int find(int queue[],int n,int key){
    for(int i=0;i<n;i++){
        if(queue[i]==key){
            return i;
        }
    }
    return -1;
}


int FCFS(int queue[],int n,int header){
    int otime=0;
    int prev=header;
    for(int i=0;i<n;i++){
        printf("%d -> %d    ",prev,queue[i]);
        int temp =(queue[i]-prev);
        if(temp<0){
            temp*=-1;
        }
        otime+=temp;
        prev=queue[i];
    }
    return otime;
}

int 
