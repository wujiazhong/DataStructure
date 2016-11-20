/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "LinkQueue.h"

Status InitQueue(LinkQueue *Q){
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q->front) exit(OVERFLOW);
    Q->front->next = NULL;
    return OK;
}

Status EnQueue(LinkQueue *Q, ElemType e){
    QueuePtr qptr = (QueuePtr)malloc(sizeof(QNode));
    if(qptr) exit(OVERFLOW);
    qptr.data = e;
    qptr->next = NULL;
    Q->rear->next = qptr;
    Q->rear = Q->rear->next;
    return OK;
}

Status DeQueue(LinkQueue *Q, ElemType &e){
    if(Q->front == Q->rear) return ERROR;
    QueuePtr qptr = NULL;
    qptr = Q->front->next;
    Q->front->next = qptr->next;
    e = qptr->data;
    if(Q->rear == qptr) Q->rear = Q->front;
    qptr->next = NULL;
    free(qptr);
    qptr = NULL;
    return OK;
}
