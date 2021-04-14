#include<bits/stdc++.h>
using namespace std;

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
    L->data = 1;
}

/* 初始化循环链表的初始值 */
void init_add(LinkList &L, int n) {
    InitList(L);
    LinkList p = L;
    for (int i = 2; i <= n;i++) {
        LinkList p_temp = new Lnode;
        p_temp->data = i;
        if (i == n) {
            p_temp->next = L;
            p->next = p_temp;
        } else {
            p_temp->next = p->next;
            p->next = p_temp;
            p = p->next;
        }
    }
}


void joseph_ring(LinkList &L, int n, int m, int k) {
    init_add(L, n);
    LinkList p = L;
    for (int i = 0; i< m; i++) {
        p = p->next;
    }
    while(p->next != p) {
        for (int j = 1; j< k; j++) {
            if (j == k-1) {
                cout<<p->next->data<<"号出来"<<"\n";
                p->next = p->next->next;
                p = p->next;
            } else {
                p = p->next;
            }
        }
    }
    cout<< p->data<<"号出来"<<"\n";

}

int main()
{
    cout << "请依次输入人数n、报数位置m、报到指定值就站起来的k值" << "\n";
    int n, m, k;
    cin >> n >> m >> k;
    LinkList p;
    joseph_ring(p, n, m, k);
}