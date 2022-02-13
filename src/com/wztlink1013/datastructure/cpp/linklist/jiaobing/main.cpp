#include<bits/stdc++.h>
using namespace std;

/**
 * 求两个集合LA和LB(用单链表表示)的并和交集
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

/* 打印 */
void TraverseList(LinkList & L){
        LinkList p = new LNode;
        p = L->next;
        cout << "此链表打印的结果为："<< "\n";
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << "\n";
}

/* 排序单链表 */
void sort(LinkList &L) {

}

/* jiao算法 */
void jiao(LinkList &A,LinkList &B) {
    // 用双循环得出共有的元素并输出
    LinkList p;
    InitList(p);
    A = A->next;
    B = B->next;
    while (A != NULL ) {
        LinkList copy_b = B;
        while(copy_b != NULL) {
            if (A->data == copy_b->data) {
                LinkList temp = new Lnode;
                temp->data = copy_b->data;
                temp->next = p->next;
                p->next = temp;
                break;
            } else {
                copy_b = copy_b->next;
            }
        }
        A = A->next;
    }
    
    while(p->next != NULL) {
        cout << p->next->data << " ";
        p = p->next;
    }
}


/* bing算法 */
void bing(LinkList &A,LinkList &B) {
    LinkList p = A;
    LinkList s = B;

    A = A->next;
    B = B->next;
    while (A != NULL ) {
        LinkList copy_b = B;
        while(copy_b != NULL) {
            if (A->data == copy_b->data) {
                // cout << A->data << "\n";
                // 在p链里面删除A->data值
                LinkList q = p;
                while(q->next != NULL) {
                    if (q->next->data == A->data) {
                        q->next = q->next->next;
                        break;
                    } else {
                        q = q->next;
                    }
                }
                break;
            } else {
                copy_b = copy_b->next;
            }
        }
        A = A->next;
    }
    // 将p链表连接到s链表上
    LinkList result = p;
    while (p != NULL) {
        if (p->next == NULL) {
            p->next = s->next;
            break;
        }
        p = p->next;
    }
    while(result->next != NULL) {
        cout << result->next->data << " ";
        result = result->next;
    }
}

int main() {
    LinkList list_A;
    LinkList list_B;
    InitList(list_A);
    InitList(list_B);
    CreateList_R(list_A, 6);
    CreateList_R(list_B, 6);
    LinkList list_C = list_A;
    LinkList list_D = list_B;
    cout <<"A、B交集的值为：";
    jiao(list_A, list_B);
    cout <<"\n"<<"A、B并集的值为：";
    bing(list_C, list_D);
}