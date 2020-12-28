#include "global.h"

#ifndef QUEUE_H
    #define QUEUE_H




    typedef struct queue{
        int front;
        int rear;
        int size;
        QueueEntry entry[MAXQUEUE];

    }Queue;


    void CreateQueue(Queue*);
    void ClearQueue(Queue* q);
    int QueueSize(Queue* q);

    void Append(QueueEntry e, Queue* q);
    void Serve(QueueEntry* e,Queue* q);

    int QueueEmpty (Queue* q);
    int QueueFull (Queue* q);

    void TraverseQueue(Queue* q,void(*f)(QueueEntry));


#endif



