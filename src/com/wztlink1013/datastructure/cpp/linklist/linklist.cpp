#include<bits/stdc++.h>
using namespace std;

/**
 * 单链表
 * 
 * 链表的基本操作：初始化、创建（前插、后插）、取值、查找、插值、删除、打印、逆置
 */


/* 单链表的存储结构 */
typedef struct LNode {
    int data; //数据域
    struct LNode *next; //指针域
}Lnode, *LinkList; //LinkList为指向结构体LNode的指针类型


/* 初始化链表 */
void InitList(LinkList &L) {
    L = new LNode;
    L->next = NULL;
}
/* 打印 */
void TraverseList(LinkList & L){
        LinkList p = new LNode;
        p = L->next;
        cout << "此链表打印的结果为："<< "\n";
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
}
/* 创建：前插 */
void CreateList_H(LinkList &L, int n) {
    InitList(L);
    for (int i = 0; i < n; i++){
        LNode *p = new LNode;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}

/* 创建：后插 */
void CreateList_R(LinkList &L, int n) {
    cout << "请输入" << n << "个数字"<< "\n";
    InitList(L);
    // 定义一个在下面循环用来一直操作所加元素的结点p来指向头结点L
    LinkList p = L;
    for (int i = 0; i < n;i++) {
        LinkList q = new Lnode;
        q->next = NULL;
        cin >> q->data;
        p->next = q;
        p = q; //为了下一次
    }
}

/* 取值 */
void GetElem(LinkList &L, int n) {
    LinkList p = L;
    for (int i = 0; i < n;i++){
        p = p->next;
    }
    cout <<n<<"的值为：" << p->data<<"\n"<<"\n";
}

/* 查找 */
void SearchElem(LinkList &L, int ele) {
    LinkList p = L;
    int count = 0;
    while (p->data != ele) {
        p = p->next;
        count++;
    }
    cout <<ele<<"这个值的索引位置是："<< count<<"\n";
}

/* 插值：在第n个位置插入ele值*/
void ListInsert(LinkList &L, int n, int ele){
    LinkList p = L;
    for (int i = 0; i < n;i++) {
        if (n == i+1){
            LinkList temp = new LNode;
            temp->data = ele;
            temp->next = p->next;
            p->next = temp;
            break;
        }
        p = p->next;
    }
    TraverseList(L); 
}

/* 删除：删除第j个位置的值 */
void ListDelete(LinkList &L, int j){
    LinkList p = L;
    for (int i = 0; i < j;i++) {
        if (j == i+1) {
            p->next = p->next->next;
            break;
        }
        p = p->next;
    }
    TraverseList(L);
}


/* 逆置 */
void ReverseList(LinkList &L) {
    LNode *p = L->next;             
    L->next = NULL;                
    while(p) {
        LinkList q = p->next;         
        p->next = L->next;          
        L->next = p;                
        p = q;                      
    }
    cout << "通过逆置之后……";
    TraverseList(L);
}

int main() {
    // LNode *test = new LNode;
    LinkList test;
    // struct LNode *test;
    CreateList_R(test,4);
    SearchElem(test, 3);
    // cout << GetEle(test, 2);
    // TraverseList(test);
    // GetElem(test,2);
    // ListInsert(test);
    // ListDelete(test);
    // ReverseList(test);
}