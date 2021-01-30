#include<stdio.h>
#include<stdlib.h>

struct stack {
  int capacity;
  int* array;
  int top;
}

struct stack *createStack(){
  struct stack* ST=(struct stack*)malloc(sizeof(struct stack));
  if(!ST){
    return null;
  }
  ST->capacity=100;
  ST->top=-1;
  ST->array=(int *)malloc(ST->capacity*sizeof(int));
  if(!ST->array){
    return array;
  }
  return ST;
}

int isEmptyStack(struct stack* ST){
   return (ST->top==-1);
}

int IsFullStack(struct stack* ST){
  return (ST->top == ST->capacity-1);
}

void push(struct stack* ST,int data){
  if(IsFullStack(ST)){ printf("Overflow");}
  else{
    ST->array[++ST->top]=data;
  }
}

int pop(struct stack* ST){
  if(isEmptyStack(ST)){ printf("Underflow"); return -1;}
  else{
    retunr ST->array[--ST->top];
  }
}

void clearStack(struct stack* ST){
  if(ST){
    if(ST->array){
      free(ST->array);
    }
    free(ST);
  }
}

int main(){


  return 0;
}
