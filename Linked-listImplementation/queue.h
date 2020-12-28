#include "global.h"

#ifndef QUEUE_H
    #define QUEUE_H


    typedef struct node {
        QueueEntry entry;
        struct node* next;
    }QueueNode;

    typedef struct {
        QueueNode* first;
        QueueNode* rear;
        int size;
    }Queue;




    void CreateQueue(Queue*);
    void ClearQueue(Queue*);

    void Append(QueueEntry,Queue*);
    void Serve(QueueEntry*,Queue*);

    int QueueEmpty(Queue*);
    int QueueFull(Queue*);

    int QueueSize(Queue*);
    void TraverseQueue(Queue*,void(*)(QueueEntry));










#endif
