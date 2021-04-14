#include<bits/stdc++.h>
using namespace std;

/**
 * 循环链表
 * 
 * 循环链表其实只需要注意最后一个结点所指向的下一个结点为头结点L就好了
 * 还要注意头结点存不存元素
 * 还有判断的时候条件不是单链表那样判断是否为空了，而是是否为头结点的值了
 */


/**
 * 定义一个单链表
 */
typedef struct LNode {
    int data;
    struct LNode *next;
}Lnode, *LinkList;

/**
 * 初始化单链表
 */
void InitList(LinkList &L) {
    L = new LNode;
    L->next = NULL;
}

/**
 * 初始化单链表并将其变成循环链表
 */

void CircleList(LinkList &L, int n) {
    InitList(L);
    // 初始化第一个结点的值
    L->data = 1;
    LinkList p = L;
    for (int i = 2; i <= n; i++) {
        LinkList temp = new Lnode;
        temp->data = i;
        if (i == n) {
            temp->next = L;
            p->next = temp;
            break;
        }
        temp->next = NULL;
        p->next = temp;
        p = p->next;
    }
}

/**
 * 打印输出用来测试是否为循环链表
 */
void PrintList(LinkList &L, int n) {
    LinkList p = L;
    for (int i = 0; i < n;i++) {
        cout << p->data << " ";
        p = p->next;
    }
}


int main() {
    LinkList test;
    CircleList(test,5);
    PrintList(test, 12);
}