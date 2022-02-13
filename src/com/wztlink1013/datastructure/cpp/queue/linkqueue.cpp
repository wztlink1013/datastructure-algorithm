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
Status EnQueue(LinkQueue &queue, QElemType e) {
    QueuePtr temp = new QNode;
    temp->data = e;
    temp->next = NULL;
    queue.rear->next = temp;
    queue.rear = temp;
    return OK;
}

/* 出队 */
Status DeQueue(LinkQueue &queue) {
    if (queue.front == queue.rear) {
        return OVERFLOW;
    }
    QElemType e = queue.front->next->data;
    queue.front->next = queue.front->next->next;
    // 考虑最后一个元素被删，队尾指针指向头结点
    if (queue.rear == queue.front) {
        queue.front = queue.rear;
    }
    return e;
}

/* 取队头元素 */
Status GetHead(LinkQueue &queue) {
    if (queue.front != queue.rear){
        return queue.front->next->data;
    }
}


int main() {
    LinkQueue test;
    InitQueue(test);
    EnQueue(test, 10);
    EnQueue(test, 15);
    EnQueue(test, 20);
    // cout << "队列长度为：" << QueueLength(test) << "\n";
    cout << GetHead(test)<<" "<< GetHead(test)<<" "<< GetHead(test)<<" "<<"\n";
    cout << DeQueue(test)<<" "<< DeQueue(test)<<" "<< DeQueue(test)<<" "<<"\n";
}