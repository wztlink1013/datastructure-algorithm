#include<bits/stdc++.h>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
}Lnode, *LinkList;

LinkList L;

void InitList(LinkList &L) {
    L = new LNode;
    L->next = NULL;
}

void CreateList_H(LinkList &L) {
    InitList(L);
    int n;
    cout << "请输入要使用前插法插入的元素个数：";
    cin >> n;
    for (int i = 0; i < n; i++){
        LNode *p = new LNode;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}
void TraverseList(LinkList &L){
    LNode *p = new LNode;
    p = L->next;
    cout << "此链表打印的结果为："<<"\n";
    while (p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}
void GetElem(LinkList &L) {
    int n;
    cout << "请输入要查询的链表中第i个数：";
    cin >> n;
    LNode *p = new LNode;
    p = L;
    for (int i = 0; i < n;i++){
        p = p->next;
    }
    cout << "查询的结果为：" << p->data<<"\n";
}
void ListInsert(LinkList &L){
    LNode *p = new LNode;
    p = L;
    int n;
    int e;
    cout << "请分别输入要在第n个位置插入的e值：";
    cin >> n>> e ;
    for (int i = 0; i < n;i++) {
        if (n == i+1){
            LNode *temp = new LNode;
            temp->data = e;
            temp->next = p->next;
            p->next = temp;
            break;
        }
        p = p->next;
    }
    TraverseList(L); 
}
void ListDelete(LinkList &L){
    cout << "请输入要删除的第j个位置的j值：";
    LNode *p = new LNode;
    p = L;
    int j;
    cin >> j;
    for (int i = 0; i < j;i++) {
        if (j == i+1) {
            p->next = p->next->next;
            break;
        }
        p = p->next;
    }
    TraverseList(L);
}
void ReverseList(LinkList &L) {
    LNode *p = L->next;             
    L->next = NULL;                
    while(p)                        
    {
        LNode *q = p->next;         
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
    CreateList_H(test);//1
    TraverseList(test);//1
    // GetElem(test);//2
    // ListInsert(test);//3
    // ListDelete(test);//4
    // ReverseList(test);//5
}