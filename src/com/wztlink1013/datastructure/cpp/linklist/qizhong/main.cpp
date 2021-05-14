#include<bits/stdc++.h>
using namespace std;

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

/* 创建：后插 */
void CreateList_R(LinkList &L, int n) {
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
/* 打印 */
void TraverseList(LinkList & L){
        LNode *p = new LNode;
        p = L->next;
        cout << "此链表打印的结果为："
             << "\n";
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << "\n";
}
/* 处理重复元素 */
void ActionList(LinkList &L) {
    // 复制原链表
    LinkList l = new LNode;
    l = L;
    // 尾巴链表
    LinkList tail = new LNode;
    InitList(tail);
    // 慢指针
    LinkList slow = new LNode;
    slow = l->next;

    while (slow->next != NULL) {
        if (slow->data == slow->next->data) {
            cout << "进来了"<< "\n";
            slow->next = slow->next->next;
        } else {
            slow = slow->next;
        }    
    }


    // 拼接上尾巴
    while (l != NULL) {
        if (l->next == NULL) {
            l->next = tail->next;
            break;
        } else {
            l = l->next;
        }
    }
}





int main() {
    int n;
    cout << "请输入结点个数n：";
    cin >> n;
    LinkList test = new LNode;
    InitList(test);
    // 处理前
    CreateList_R(test, n);
    TraverseList(test);
    // 处理后
    ActionList(test);
    TraverseList(test);
}