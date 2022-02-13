#include<bits/stdc++.h>
using namespace std;

typedef struct LNode {
    int data;
    int flag;
    struct LNode *next;
}Lnode, *LinkList;

int main() {
    LinkList L;
    L = new LNode;
    L->data = 1;
    L->flag = 1;
    L->next = NULL;
    for (int i = 1; i < 10;i++) {
        LinkList p;
        p = new LNode;
        p->data = 11-i;
        p->flag = 1;
        p->next = L->next;
        L->next = p;
        if (i == 1){
            p->next = L;
        }
    }

    LinkList s;
    s = new LNode;
    s = L;
    for (int i = 0; i < 1000;i++) {
        s->flag = 0;
        for (int j = 0; j < i+2;j++) {
            s = s->next;
        }
    }
    cout << "最终结果："<< "\n";
    for (int i = 0; i < 10;i++){
        cout << L->data <<"洞"<< " " << L->flag << "\n";
        L = L->next;
    }
}