#include<bits/stdc++.h>
using namespace std;

typedef int Status;
typedef int QElemType;

#define OVERFLOW -1
#define ERROR 0
#define OK 1
#define MAXSIZE 100

/**
 * 循环队列——队列的顺序表示和实现
 * 
 * 操作：初始化、队列长度、入队、出队、取队头元素
 */

/* 存储形式 */
typedef struct {
    QElemType *base;
    int front;
    int rear;
} SqQueue;

/* 初始化 */
Status InitQueue(SqQueue &queue) {
    // 初始化这个base地址为一个有最大容量的数组初地址
    queue.base = new int[MAXSIZE];
    if (!queue.base) {
        return OVERFLOW;
    }
    queue.front = queue.rear = 0;
    return OK;
}

/* 求队列长度 */
Status QueueLength(SqQueue &queue) {
    return (queue.rear - queue.front + MAXSIZE) % MAXSIZE;
}

/* 入队 */
Status EnQueue(SqQueue &queue, QElemType e) {
    if ((queue.rear+1)%MAXSIZE == queue.front) {
        return OVERFLOW;
    }
    queue.base[queue.rear] = e;
    queue.rear = (queue.rear + 1) % MAXSIZE;
    return OK;
}

/* 出队 */
Status DeQueue(SqQueue &queue) {
    if ((queue.rear+1)%MAXSIZE == queue.front) {
        return OVERFLOW;
    }
    QElemType e = queue.base[queue.front];
    queue.front = (queue.front + 1) % MAXSIZE; //队头指针+1
    return e;
}

/* 取队头元素 */
Status GetHead(SqQueue &queue) {
    if (queue.front != queue.rear) {
        return queue.base[queue.front];
    }
}


int main() {
    SqQueue test;
    InitQueue(test);
    EnQueue(test, 10);
    EnQueue(test, 15);
    EnQueue(test, 20);
    cout << "队列长度为：" << QueueLength(test) << "\n";
    cout << GetHead(test)<<" "<< GetHead(test)<<" "<< GetHead(test)<<" "<<"\n";
    cout << DeQueue(test)<<" "<< DeQueue(test)<<" "<< DeQueue(test)<<" "<<"\n";
}