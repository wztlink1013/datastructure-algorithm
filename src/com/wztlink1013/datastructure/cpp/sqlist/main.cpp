#include<bits/stdc++.h>
using namespace std;
typedef int Status;
typedef int ElemType;
#define OVERFLOW -1
#define ERROR 0
#define OK 1

//-----顺序表的储存结构-----
#define MAXSIZE 100
typedef struct 
{
    ElemType *elem;
    int length;
}SqList;

SqList L;

//1、顺序表初始化
Status InitList(SqList &L)
{//构造一个空的顺序表L
    L.elem = new ElemType[MAXSIZE];     //为顺序表分配一个大小为MAXSIZE的数组空间
    if(!L.elem)                         //如果分配失败，则L.elem会指向NULL，即此判断为真
        exit(OVERFLOW);                 //储存分配失败退出
    L.length = 0;                       //空表长度为0
    return OK;
}

//2、顺序表销毁
Status DestroyList(SqList &L)
{
    delete []L.elem;
    L.elem = NULL;
    L.length = 0;
    return OK;
}

//3、顺序表清空
Status ClearList(SqList &L)
{
    L.length = 0;
    return OK;
}

//4、顺序表空表
Status ListEmpty(SqList L)
{
    if(L.length == 0)
        return OK;
    return ERROR;
}

//5、顺序表表长
Status ListLength(SqList L)
{
    return L.length;
}

//6、顺序表取值 O(1)
Status GetElem(SqList L, int i, ElemType &e)
{
    if(i < 1 || i > L.length)   //判断i值是否合理，若不合理，返回ERROR
        return ERROR;
    e = L.elem[i - 1];          //elem[i - 1]储存第i个数据元素
    return OK;
}

//7、顺序表查找 O(n)
Status LocateElem(SqList L, ElemType e)
{//再顺序表中查找值为e的元素，返回其序号
    for(int i = 0; i < L.length; i++)
        if(L.elem[i] == e)
            return i + 1;               //查找成功，返回序号i + 1
    return ERROR;                       //查找失败，返回0
}

//8、顺序表前驱
Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
    for(int i = 0; i < L.length; i++)
        if(L.elem[i] == cur_e)
        {
            pre_e = L.elem[i - 1];
            return OK;
        }
    return ERROR; 
}

//9、顺序表后继
Status NextElem(SqList L, ElemType cur_e, ElemType &next_e)
{
    for(int i = 0; i < L.length; i++)
        if(L.elem[i] == cur_e)
        {
            next_e = L.elem[i + 1];
            return OK;
        }
    return ERROR;   
}

//10、顺序表插入 O(n)
Status ListInsert(SqList &L, int i, ElemType e)
{//在顺序表L中第i个位置之前插入新的元素e, i值的合法范围是1 <= i <= L.length+1
    if(i < 1 || i > L.length + 1)               //i值不合法
        return ERROR;
    if(L.length == MAXSIZE)                 //当前存储空间已满
        return ERROR;
    for(int j = L.length - 1; j >= i - 1; j--)
        L.elem[j + 1] = L.elem[j];          //插入位置之后的元素后移
    L.elem[i - 1] = e;                      //将新元素e放在第i个位置
    L.length++;                             //表长+1
    return OK; 
}


//11、顺序表删除 O(n)
Status ListDelete(SqList &L, int i)
{//在顺序表L中删除第i个元素， i值的合法范围是1<=i<=L.length
    if(i < 1 || i > L.length)
        return ERROR;                           //i值不合法
    for(int j = i; j <= L.length - 1; j++)
        L.elem[j - 1] = L.elem[j];              //被删除元素之后的元素前移
    L.length--;                                 //表长减1
    return OK;
}

//12、顺序表遍历 O(n)
Status TraverseList(SqList L)
{
    for(int i = 0; i < L.length; i++)
    {
        if(i == L.length - 1)
            cout<<L.elem[i]<<'\n';
        else
            cout<<L.elem[i]<<' ';
    }
    return OK;
}

//实验1：顺序表的建立及运算
int main()
{
    cout<<"--------------------顺序表菜单--------------------"<<'\n';
    cout<<"操作0：退出程序"<<'\n';
    cout<<"操作1：建立一个顺序表，输入n个元素并输出"<<'\n';
    cout<<"操作2：查找线性表中的最大元素并输出"<<'\n';
    cout<<"操作3：在线性表的第i个元素前插入一个正整数x"<<'\n';
    cout<<"操作4：删除线性表中的第j个元素"<<'\n';
    cout<<"操作5：将线性表中的元素按升序排列"<<'\n';
    cout<<"操作6：将线性表中的元素就地逆序（只允许用一个暂存单元）"<<'\n';
    cout<<"--------------------------------------------------"<<'\n';
    int a, n, flag = 1;
    while(flag)
    {
        cout<<'\n'<<"请选择要执行的操作：";
        cin>>a;
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
                cout<<"请输入要建立的顺序表的元素个数：";
                cin>>n;
                cout<<"请按顺序输入这"<<n<<"个元素：";
                ElemType e;
                InitList(L);
                for(int i = 1; i <= n; i++)
                {
                    cin>>e;
                    ListInsert(L, i, e);
                }
                cout<<"顺序表创建完毕：";
                TraverseList(L);
                break;
            }
            case 2:
            {
                int maxIndex = 0;
                for(int i = 1; i < L.length; i++)
                    if(L.elem[maxIndex] < L.elem[i])
                        maxIndex = i;
                cout<<"线性表中的最大元素为："<<L.elem[maxIndex]<<'\n';
                break;
            }
            case 3:
            {
                int i, x;
                cout<<"在线性表的第i个元素前插入一个正整数x，请依次输入i和x的值：";
                cin>>i>>x;
                if(ListInsert(L, i, x))
                {
                    cout<<"顺序表插入完毕：";
                    TraverseList(L);
                }
                else
                    cout<<"顺序表插入不合法！"<<'\n';
                break;
            }
            case 4:
            {
                int j;
                cout<<"删除线性表中的第j个元素，请输入j的值：";
                cin>>j;
                if(ListDelete(L, j))
                {
                    cout<<"顺序表删除完毕：";
                    TraverseList(L);
                }
                else
                    cout<<"顺序表删除不合法！"<<'\n';
                break;
            }
            case 5:
            {
                for(int i = 0; i < L.length - 1; i++)
                {
                    int minIndex = i;
                    for(int  j = i; j < L.length - 1; j++)
                    {
                        if(L.elem[minIndex] > L.elem[j + 1])
                            minIndex = j + 1;
                    }
                    int tmp = L.elem[i];
                    L.elem[i] = L.elem[minIndex];
                    L.elem[minIndex] = tmp;
                }
                cout<<"顺序表升序排列完毕：";
                TraverseList(L);
                break;
            }
            case 6:
            {
                for(int i = 0; i < L.length / 2; i++)
                {
                    int tmp = L.elem[i];
                    L.elem[i] = L.elem[L.length - i - 1];
                    L.elem[L.length - i - 1] = tmp;
                }
                cout<<"顺序表就地逆序完毕：";
                TraverseList(L);
                break;
            }
        }
    }
    return 0;
}
