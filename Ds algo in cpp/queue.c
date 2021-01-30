#include<stdio.h>
#include<stdlib.h>

struct Queue{
  int capacity;
  int rear,front;
  int *array;
}

struct Queue *createQueue(){
  struct Queue* que=(struct Queue*)malloc(sizeof(struct Queue));
  que->capacity=100;
  que->front=que->rear=-1;
  que->array=(int *)malloc(que->capacity*sizeof(int));
  return que;
}

int isEmptyQueue(struct Queue* que){
  return (que->front==-1);
}

int isFullQueue(struct Queue* que){
    return ((que->rear+1)%que->capacity==(que->front));
}

int queueSize(struct Queue* que){
  return (que->capacity+que->rear-que->front+1)%que->capacity;
}

void Enque(struct Queue* que,int data){
  if(isFullQueue(que)){printf("Overflow \n", ); return ;}
  que->rear=(que->rear+1)%que->capacity;
  que-> 
}

int main(){
  return 0;
}
