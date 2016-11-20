/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GLNode.h
 * Author: wujz
 *
 * Created on November 13, 2016, 8:10 PM
 */

#ifndef GLNODE_H
#define GLNODE_H

typedef enum {ATOM, LIST} ElemTag;
typedef struct GLNode {
    ElemTag tag;
    union {
        ElemType atom;
        struct GLNode *hp;
    };
    struct GLNode *tp;
} *GList;

#endif /* GLNODE_H */

