#include<bits/stdc++.h>
using namespace std;

typedef int Status;
typedef int QElemType;

#define OVERFLOW -1
#define ERROR 0
#define OK 1

/**
    实验4：队列的链式表示和实现
    要求：某小超市有两个排队机，构建2个用带头结点的单链表队列QA和QB, 实现下列操作
        1、初始化队列(清空)；
        2、入队；
        3、出队;
        4、求队列长度；
        5、判断队列是否为空；
        6、判断队列是否为满；
        7、对于队列QA和QB，如果其中一个队列的售货员下班，则自动甩到另一个队列后面。

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

/* 求队列长度 */
Status QueueLength(LinkQueue &queue) {
    int count = 0;
    if (queue.rear == queue.front) {
        return count;
    }
    QueuePtr temp = queue.front;
    while (temp != queue.rear) {
        count++;
        temp = temp->next;
    }
    return count;
}

/* 入队 */
Status EnQueue(LinkQueue &queue, QElemType e, int length) {
    if (QueueLength(queue) <length) {
        QueuePtr temp = new QNode;
        temp->data = e;
        temp->next = NULL;
        queue.rear->next = temp;
        queue.rear = temp;
        return OK;
    } else {
        cout << "队已经满了，不能再入元素了"<< "\n";
        return ERROR;
    }
}

/* 出队 */
Status DeQueue(LinkQueue &queue) {
    if (queue.front == queue.rear) {
        return OVERFLOW;
    }
    // 有必要定义一个p，不然头结点会掉
    QueuePtr p = queue.front->next;
    QElemType e = p->data;
    queue.front->next = p->next;
    // 考虑最后一个元素被删，队尾指针指向头结点
    if (queue.rear == p) {
        queue.rear = queue.front;
    }
    return e;
}

/* 取队头元素 */
// Status GetHead(LinkQueue &queue) {
//     if (queue.front != queue.rear){
//         return queue.front->next->data;
//     }
// }



/* 判断队列是否为空 */
bool QueueIsEmpty(LinkQueue &queue) {
    if (queue.rear == queue.front) {
        return true;
    } else {
        return false;
    }
}

/**
 * 判断队列是否为满
 * 不是很理解为什么链队需要判断是否为满呢？
 * 采用输入链队长度，利用链队函数来判断
 * 那么入队的代码需要输入length参数来判断是否还能让元素入队
 */
bool QueueIsFull(LinkQueue &queue, int length) {
    if (QueueLength(queue) == length) {
        return true;
    } else {
        return false;
    }
}

/* 一个队列甩到另一个队列 */
Status QueueMove(LinkQueue &queue_delete,LinkQueue &queue_add) {
    queue_add.rear->next = queue_delete.front->next;
    queue_add.rear = queue_delete.rear;
    return OK;
}

/* 遍历查看队列元素 */
Status DisplayQueue(LinkQueue &queue) {
    LinkQueue L = queue;
    while (L.front->next != NULL) {
        cout << L.front->next->data << " ";
        L.front = L.front->next;
    }
    cout << "\n";
    return OK;
}

int main() {
 
    cout<<"------------------------链队菜单----------------------"<<'\n';
    cout<<"操作0：退出程序"<<'\n';
    cout<<"操作1：初始化两队列"<<'\n';
    cout<<"操作2：入队操作"<<'\n';
    cout<<"操作3：出队操作"<<'\n';
    cout<<"操作4：判断判断链队是否为空"<<'\n';
    cout<<"操作5：判断判断链队是否为满"<<'\n';
    cout<<"操作6：售货员偷懒选项"<<'\n';
    cout<<"操作7：查看队列"<<'\n';
    cout<<"操作8：求队列长度"<<'\n';
    cout<<"--------------------------------------------------------"<<'\n';
    int a, length,flag = 1;
    cout << "请输入你希望排队机最多能排的人数："<<"\n"<<"\n";
    cin >> length;
    LinkQueue QA,QB;
    while(flag)
    {
        cout<<'\n'<<"请选择要执行的操作：";
        while(cin>>a)
        {
            if(a < 0 || a > 8)
                cout<<"请选择正确操作编号：";
            else
                break;
        }
        switch(a)
        {
            case 0:
            {
                cout<<"正在退出程序中……"<<'\n';
                flag = 0;
                break;
            }
            case 1:
            {
                cout<<"初始化QA、QB队列中……"<<'\n';
                InitQueue(QA);
                InitQueue(QB);
                break;
            }
            case 2:
            {
                cout<<"请输入入队的队列（QA输入1，QB输入2）"<<'\n';
                int select_queue;
                cin >> select_queue;
                if (select_queue == 1) {
                    cout<<"请输入入QA队的队列的元素"<<'\n';
                    int select_queue_A;
                    cin >> select_queue_A;
                    EnQueue(QA, select_queue_A, length);
                } else if (select_queue == 2) {
                    cout<<"请输入入QB队的队列的元素"<<'\n';
                    int select_queue_B;
                    cin >> select_queue_B;
                    EnQueue(QB, select_queue_B, length);
                } else {
                    cout << "输入有误！"<< "\n";
                }
                break;
            }
            case 3:
            {
                cout<<"请输入需要出队的队列（QA输入1，QB输入2）"<<'\n';
                int select_queue;
                cin >> select_queue;
                if (select_queue == 1) {
                    DeQueue(QA);
                } else if (select_queue == 2) {
                    DeQueue(QB);
                } else {
                    cout << "输入有误！"<< "\n";
                }
                break;
            }
            case 4:
            {
                cout<<"请输入需要判空的队列（QA输入1，QB输入2）"<<'\n';
                int select_queue;
                cin >> select_queue;
                if (select_queue == 1) {
                    cout << "QA队列为空吗？"<< boolalpha << QueueIsEmpty(QA) << "\n";
                } else if (select_queue == 2) {
                    cout << "QB队列为空吗？"<< boolalpha << QueueIsEmpty(QB) << "\n";
                } else {
                    cout << "输入有误！"<< "\n";
                }
                break;
            }
            case 5:
            {
                cout<<"请输入需要判满的队列（QA输入1，QB输入2）"<<'\n';
                int select_queue;
                cin >> select_queue;
                if (select_queue == 1) {
                    cout << "QA队列为满吗？"<< boolalpha << QueueIsFull(QA,length) << "\n";
                } else if (select_queue == 2) {
                    cout << "QB队列为满吗？"<< boolalpha << QueueIsFull(QB,length) << "\n";
                } else {
                    cout << "输入有误！"<< "\n";
                }
                break;
            }
            case 6:
            {
                cout<<"请输入下班的售货员（QA输入1，QB输入2）"<<'\n';
                int select_queue;
                cin >> select_queue;
                if (select_queue == 1) {
                    QueueMove(QA, QB);
                } else if (select_queue == 2) {
                    QueueMove(QB, QA);
                } else {
                    cout << "输入有误！"<< "\n";
                }
                break;
            }
            case 7:
            {
                cout<<"请输入要查看的队列（QA输入1，QB输入2）"<<'\n';
                int select_queue;
                cin >> select_queue;
                if (select_queue == 1) {
                    DisplayQueue(QA);
                } else if (select_queue == 2) {
                    DisplayQueue(QB);
                } else {
                    cout << "输入有误！"<< "\n";
                }
                break;
            }
            case 8:
            {
                cout<<"请输入要查看的队列的长度（QA输入1，QB输入2）"<<'\n';
                int select_queue;
                cin >> select_queue;
                if (select_queue == 1) {
                    cout<<QueueLength(QA)<< "\n";
                } else if (select_queue == 2) {
                    cout<<QueueLength(QB)<< "\n";
                } else {
                    cout << "输入有误！"<< "\n";
                }
                break;
            }
        }
    }
}