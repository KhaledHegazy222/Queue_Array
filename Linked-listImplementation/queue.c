#include "global.h"
#include "queue.h"
#include <stdlib.h>


void CreateQueue (Queue* q){
    q->first = NULL;
    q->rear = NULL;
    q->size = 0;
}

void Append(QueueEntry e, Queue* q){
    QueueNode* p = (QueueNode*)malloc(sizeof(QueueNode));
    p->next = NULL;
    p->entry = e;

    // empty queue = q->first = q->rear = NULL
    if(!q->first){
        q->first = p;
    }
    else{
        q->rear->next = p;//runtime error for empty queue so this is a special case
    }

    q->rear  = p;
    q->size++;
}

void Serve(QueueEntry* e, Queue* q){
    QueueNode* p;
    p = q->first;
    *e = p->entry;
    q->first = p->next;
    // one element queue = q->first->next = q->rear->next = NULL
    if(!p->next){
        q->rear = NULL;
    }
    free(p);
    q->size--;
}


int QueueEmpty(Queue* q){
    return !q->first;
    // the same as return !q->rear
    // the same as return q->size (any number != 0 is true )
}

int QueueFull(Queue* q){
    return 0;
}


int QueueSize(Queue* q){
    return q->size;
}


void ClearQueue(Queue* q){
    while(q->first){
        q->rear = q->first->next;
        free(q->first);
        q->first = q->rear;
    }
    q->size = 0;
}




void TraverseQueue(Queue* q,void(*f)(QueueEntry)){
    QueueNode* p = q->first;
    while(p){
        (*f)(p->entry);
        p = p->next;
    }
}






