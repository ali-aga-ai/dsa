/*here we gotta use a sliding window so attemtping a dequeue*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_SIZE 100

struct Queue{
    //this will be treated as a DOuble ended Queue(deque)
    int first;//index of first element
    int last;//index of last element+1
    int a[QUEUE_SIZE];

};


void qPush(struct Queue *queue, int element){
    queue->a[queue->last] = element;
    queue->last++;
    if(queue->first==-1){
        queue->first++;
    }
}

int qPop(struct Queue *queue){
    if(queue->first!=queue->last){
        int x =  queue->a[queue->first];
        queue->first++;
        return x;
    }
    else{
        return -1;//indicating error that queue is empty
    }

    }

int q_length(struct Queue *queue){
    return queue->last-queue->first;
}

int main(){

    int n;

    scanf("%d",&n);

    int a[n];

    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }

    int b[n];

    struct Queue *q = malloc(sizeof(struct Queue));

    q->first = -1;

    int i=0;
    int j=0;
    int count = 0;
    

    while(q->first != n-1){
        //till the queue doesnt reach the last element
        bool found = false;

        qPush(q,a[i++]);
        
        if(q_length(q)==1){
            qPush(q,a[i++]);
            count++;
        }
        
       

        while(q->a[q->first]>=q->a[(q->last)-1]){
            
            qPush(q,a[i++]);
            count++;

            if(q->last==n){//condition for bigger element not found
                b[j++] = 0;
                qPop(q);
                q->last = q->first +1;
                found = false;
                break;
            }
    
        }

        if(found){
            b[j++] = count;
            qPop(q);
        }

        if(count == 0){
            int x = q->first;

            while(q->a[q->first] > q->a[q->first +1]){
                q->first++;
                count++;
            }
            b[j++] = count;
            q->first = x;
        }




    }


    return 0;
}