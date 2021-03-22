#include<bits/stdc++.h>
using namespace std;
typedef int Status;
typedef int ElemType;
#define OVERFLOW -1
#define ERROR 0
#define OK 1

//-----单链表的储存结构-----
typedef struct LNode
{
    ElemType data;              //结点的数据域
    struct LNode *next;         //结点的指针域
}LNode, *LinkList;              //LinkList为指向结构体LNode的指针类型

LinkList L;

//1、单链表初始化 O(1)
Status InitList(LinkList &L)
{//构造一个带头结点的空单链表L
    L = new LNode;              //生成新的结点作为头结点，用头指针L指向头结点
    L->next = NULL;             //头结点的指针域置空
    return OK;
}

//6、单链表取值 O(n)
Status GetElem(LinkList L, int i, ElemType &e)
{//在带头结点的单链表L中根据序号i获取元素的值，用e返回L中第i个元素的值
    LNode *p = L->next;             //p指向首元结点
    int j = 1;                      //计数器j初值赋为1
    while(p && j < i)               //直到p为空或p指向第i个元素时停止
    {
        p = p->next;                //p指向下一个结点               
        j++;                        //计数器j相应加1                       
    }
    if(!p || j > i)                 //i值不合法，即i > n或i < 1
        return ERROR;
    e = p->data;                    //取第i个结点的数据域
    return OK;
}

//7、单链表查找 O(n)
LNode *LocateElem(LinkList L, ElemType e)
{//在带头结点的单链表中查找值为e的元素，返回e的地址（所以LNode *LocateElem）
    LNode *p = L->next;             //p指向首元结点
    while(p && p->data != e)        //直到p为空或p所指结点的数据域等于e时停止
        p = p->next;                //p指向下一个结点
    return p;                       //查找成功返回值为e的结点地址p，查找失败p为NULL
}

//10、单链表插入 O(n)
Status ListInsert(LinkList &L, int i, ElemType e)
{//在带头结点的单链表L中第i个位置插入值为e的新结点
    LNode *p = L;                   //p指向头结点
    int j = 0;                      //计数器j初值赋为0
    while(p && j < i - 1)           //直到p为空或p指向第i-1个结点时停止
    {
        p = p->next;                //p指向下一个结点
        j++;                        //计数器j相应加1
    }                               
    if(!p || j > i - 1)             //i值不合法，即i > n + 1或i < 1
        return ERROR;
    LNode *s = new LNode;           //生成新结点*s
    s->data = e;                    //将结点*s的数据域置为e
    s->next = p->next;              //先接后链
    p->next = s;                    //再接前链
    return OK; 
}

//11、单链表删除 O(n)
Status ListDelete(LinkList &L, int i)
{//在带头结点的单链表L中，删除第i个元素
    LNode *p = L;                   //p指向头结点
    int j = 0;                      //计数器j初值赋为0
    while(p->next && j < i - 1)     //直到p的后继为空或p指向第i-1个结点时停止
    {
        p = p->next;                //p指向下一个结点
        j++;                        //计数器j相应加1
    }                               
    if(!(p->next) || j > i - 1)     //i值不合法，即i > n或i < 1
        return ERROR;               
    LNode *q = p->next;             //临时保存被删结点的地址以备释放
    p->next = q->next;              //前驱接后驱
    delete q;                       //释放删除结点的空间
}   

//12、单链表遍历 O(n)
Status TraverseList(LinkList L)
{
    LNode *p = L->next;             
    while(p->next)
    {
        cout<<p->data<<' ';
        p = p->next;
    }
    cout<<p->data<<'\n';
    return OK;
}

//13、前插法创建单链表 O(n)
void CreateList_H(LinkList &L, int n)
{//逆位序输入n个元素的值，建立带头结点的单链表L
    L = new LNode;                  //先初始化一个带头结点的空链表
    L->next = NULL;                 
    for(int i = 0; i < n; i++)
    {
        LNode *p = new LNode;       //生成新结点*p
        cin>>p->data;               //输入元素值赋给新结点*p的数据域
        p->next = L->next;          //先接后链
        L->next = p;                //再接前链，将新结点*p插入到头结点之后
    }
}

//14、后插法创建单链表 O(n)
void CreateList_R(LinkList &L, int n)
{//正位序输入n个元素的值，建立带头结点的单链表L
    L = new LNode;                  //先初始化一个带头结点的空链表
    L->next = NULL;                 
    LNode *r = L;                   //尾指针r先指向头结点
    for(int i = 0; i < n; i++)
    {
        LNode *p = new LNode;       //生成新结点*p
        cin>>p->data;               //输入元素值赋给新结点*p的数据域
        p->next = NULL;             //后置空后链             
        r->next = p;                //再接前链
        r = p;                      //r指向新的尾结点*p
    }
}

//15、单链表就地逆置 O(n)
void ReverseList(LinkList &L)
{
    LNode *p = L->next;             //p指向首元结点，保留原链表往后的所有结点
    L->next = NULL;                 //逆置链表的首元结点置为空
    while(p)                        //直到p为空时停止
    {
        LNode *q = p->next;         //q指向当前处理结点的下一个结点，保留原链表往后所有节点
        p->next = L->next;          //先接后链
        L->next = p;                //在接前链
        p = q;                      //把q保留的还给p
    }
}

//实验2：单链表的创建及操作
int main()
{
    cout<<"------------------------单链表菜单----------------------"<<'\n';
    cout<<"操作0：退出程序"<<'\n';
    cout<<"操作1：创建一个带头结点的单链表，且遍历此链表"<<'\n';
    cout<<"操作2：查找单链表中的第i个结点，并输出结点元素的值"<<'\n';
    cout<<"操作3：在单链表中的第i个结点前插入一个结点值为e的正整数"<<'\n';
    cout<<"操作4：删除单链表中的第j个结点"<<'\n';
    cout<<"操作5：将单链表中的各结点就地逆序（不允许另建一个链表）"<<'\n';
    cout<<"--------------------------------------------------------"<<'\n';
    int a, n, flag = 1;
    while(flag)
    {
        cout<<'\n'<<"请选择要执行的操作：";
        while(cin>>a)
        {
            if(a < 0 || a > 5)
                cout<<"请选择正确操作编号：";
            else
                break;
        }
        switch(a)
        {
            case 0:
            {
                cout<<"感谢使用本程序，祝您生活愉快！"<<'\n';
                flag = 0;
                break;
            }
            case 1:
            {
                cout<<"----菜单-----"<<'\n';
                cout<<"操作1：前插法"<<'\n';
                cout<<"操作2：后插法"<<'\n';
                cout<<"-------------"<<'\n';
                cout<<"请选择单链表的创建方式：";
                int b;
                while(cin>>b)
                {
                    if(b != 1 && b != 2)
                        cout<<"请选择正确操作编号：";
                    else
                        break;
                }
                cout<<"请输入要建立的单链表的元素个数：";
                cin>>n;
                if(b == 1)
                {
                    cout<<"请按逆位序依次输入这"<<n<<"个元素：";
                    CreateList_H(L, n);
                }
                else if(b == 2)
                {
                    cout<<"请按正位序依次输入这"<<n<<"个元素：";
                    CreateList_R(L, n);
                }
                cout<<"单链表创建完毕：";
                TraverseList(L);
                break;
            }
            case 2:
            {
                int i;
                ElemType e;
                cout<<"查找单链表中的第i个结点,请输入i的值：";
                cin>>i;
                if(GetElem(L, i, e))
                    cout<<"单链表中的第"<<i<<"个结点元素为："<<e<<'\n';
                else
                    cout<<"i值不合法！"<<'\n';
                break;
            }
            case 3:
            {
                int i;
                ElemType e;
                cout<<"在单链表中的第i个结点前插入一个结点值为e的正整数，请依次输入i和e的值：";
                cin>>i>>e;
                if(ListInsert(L, i, e))
                {
                    cout<<"单链表插入完毕：";
                    TraverseList(L);
                }
                else
                    cout<<"i值不合法！"<<'\n';
                break;
            }
            case 4:
            {
                int j;
                cout<<"删除单链表中的第j个结点，请输入j的值：";
                cin>>j;
                if(ListDelete(L, j))
                {
                    cout<<"单链表删除完毕：";
                    TraverseList(L);
                }
                else
                    cout<<"j值不合法！"<<'\n';
                break;
            }
            case 5:
            {
                ReverseList(L);
                cout<<"单链表就地逆置完毕：";
                TraverseList(L);
                break;
            }
        }
    }
    return 0;
}
