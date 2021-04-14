#include<bits/stdc++.h>
using namespace std;

/**
 * 双向链表
 * 记住一点，删除哪个结点就操作哪个结点
 */


/* 双向链表的存储结构 */
typedef struct DuLNode {
    int data; 
    struct DuLNode *prior; 
    struct DuLNode *next; 
}DuLnode, *DuLinkList; 

/* 双向链表的初始化 */
void InitDuLinkList(DuLinkList &L) {
    L = new DuLNode;
    L->prior = NULL;
    L->next = NULL;
}

int main() {
    DuLinkList L;
    InitDuLinkList(L);
    // 初始化初始节点值为100
    L->data = 100;
    // 在L结点前面插值50
    DuLinkList L_prior;
    L_prior->data = 50;
    L_prior->next = L;
    L->prior = NULL;
    L->prior = L_prior;
    // 在L结点后面插值150
    DuLinkList L_next;
    L_next->data = 150;
    L_next->prior = L;
    L_next->next = NULL;
    L->next = L_next;
    cout << L_prior->data << " " << L_prior->next->data << " " << L_prior->next->next->data<<"\n";
    // 在50和100之间插值75（只操作L结点）
    DuLinkList L_prior_L;
    L_prior_L->data = 75;
    L_prior_L->prior = L->prior;
    L->prior->next = L_prior_L;
    L_prior_L->next = L;
    L->prior = L_prior_L;
    cout << L->prior->prior->data << " " << L->prior->data << " " << L->data <<" "<< L->next->data<<"\n";
    // 删除75这个值的结点(记住一点，删除哪个结点就操作哪个结点)
    L_prior_L->next->prior = L_prior_L->prior;
    L_prior_L->prior->next = L_prior_L->next;
    cout << L->prior->data << " " << L->data << " " << L->next->data << "\n";
}