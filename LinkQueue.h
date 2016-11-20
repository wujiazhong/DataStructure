/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkQueue.h
 * Author: wujz
 *
 * Created on November 9, 2016, 9:15 PM
 */

#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include "Status.h"
#include "ElemType.h"

typedef struct {
    ElemType data;
    QNode *next;
}QNode, *QueuePtr;

typedef struct {
    QNode *front;
    QNode *rear;
}LinkQueue;

Status InitQueue(LinkQueue *);
Status EnQueue(LinkQueue *, ElemType);
Status DeQueue(LinkQueue *, ElemType &);

#endif /* LINKQUEUE_H */

