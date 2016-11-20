/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MPNode.h
 * Author: wujz
 *
 * Created on November 20, 2016, 4:38 PM
 */

#ifndef MPNODE_H
#define MPNODE_H

#include "Status.h"

typedef enum {ATOM, LIST}ElemTag;

typedef struct MPNode {
    ElemTag tag;
    int exp;
    union {
        float coef;
        struct MPNode *hp;
    };
    struct MPNode *tp;
}*MPList;

Status InitMPList();

#endif /* MPNODE_H */

