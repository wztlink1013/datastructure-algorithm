#include<bits/stdc++.h>
using namespace std;

typedef int Status;
typedef int QElemType;

#define OVERFLOW -1
#define ERROR 0
#define OK 1
#define MAXSIZE 100

/**
 * 链队——队列的链式表示和实现
 * 
 * 操作：初始化、入队、出队、取队头元素
 */

/* 存储形式 */
typedef struct QNode{ //链队用的结点
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

/* 初始化 */
Status InitQueue(LinkQueue &queue) {
    queue.front = queue.rear = new QNode;
    queue.front->next = NULL;
    return OK;
}

/* 入队 */


/* 出队 */


/* 取队头元素 */


