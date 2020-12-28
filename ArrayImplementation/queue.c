#include "global.h"

#include "queue.h"



void CreateQueue(Queue* q){
    /*
    q->front = MAXQUEUE - 1;
    q->rear = 0;
    */
    // consider that the MAXQUEUE is 1 this would mean that front = 0 and rear = 0
    //and this doesn't mean that the queue is empty
    //so it's better to make front = 0 and rear = -1
    q->front = 0;
    q->rear = -1;
    q->size = 0;

}



void Append(QueueEntry e, Queue* q){
    if(q->rear = MAXQUEUE-1){
        q->rear =  0;
    }
    else{
        q->rear++;
    }
    // Abreviation => in one line using mod (%)
    // q->rear = ( q->rear+1) % MAXQUEUE
    q->entry[q->rear] = e;
    q->size++;

}



void Serve(QueueEntry* e,Queue* q){
    *e = q->entry[q->front];
    q->front = (q->front + 1) % MAXQUEUE;
    q->size--;
}



int QueueEmpty (Queue* q){
    return !q->size;
    // return q->size == 0
}

int QueueFull (Queue* q){
    return q->size == MAXQUEUE;
}



int QueueSize(Queue* q){
    return q->size;
}

void ClearQueue(Queue* q){
    q->size = 0;
    q->front = 0;
    q->rear = -1;
}




void TraverseQueue(Queue* q,void(*f)(QueueEntry)){
    int i = q->front;
    for(int s = 0; s < q->size ; s++){
        (*f)(q->entry[i]);
        i = (i+1) % MAXQUEUE;
    }
}
