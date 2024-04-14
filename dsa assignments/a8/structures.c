#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//i will design a stack, queue, linked list

#define STACK_SIZE 100
#define QUEUE_SIZE 100

struct Stack{//assuming stack stores int values

    int top;//index of topmost element
    int a[STACK_SIZE];

};


//stack push,pop........queue push to back, pop from front, pop from back

void sPush(struct Stack *stack, int element){

    stack->a[stack->top+1] = element;
    stack->top +=1;
}

int sPop(struct Stack *stack){
    int x = stack->a[stack->top];
    stack->top-=1;
    return x;
}

struct Queue{
    //this will be treated as a DOuble ended Queue(deque)
    int first;//index of first element
    int last;//index of last element+1
    int a[QUEUE_SIZE];

};


void qPush_back(struct Queue *queue, int element){
    queue->a[queue->last] = element;
    queue->last++;
    if(queue->first==-1){
        queue->first++;
    }
}

int qPop_front(struct Queue *queue){
    if(queue->first!=queue->last){
        int x =  queue->a[queue->first];
        queue->first++;
        return x;
    }
    else{
        return -1;//indicating error that queue is empty
    }

    }

void qPush_front(struct Queue *queue, int element){
    //assuming that there is space before index 0, i.e assuming there are acceptable indexes before q->first (ie q->first -1 ==-1 nahi chalega)
    queue->a[queue->first -1] = element;
    queue->first--;
}
int qPop_back(struct Queue *queue){

     int x = queue->a[queue->last-1];
     queue->last--;
     return x;   


}



int main(){

    struct Stack *s = malloc(sizeof(struct Stack));
    s->top = -1;

    struct Queue *q = malloc(sizeof(struct Queue));
    q->first = -1;
    q->last = 0;


    return 0;
}