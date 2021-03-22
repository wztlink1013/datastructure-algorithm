#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 100

typedef struct 
{
    int *elem;
    int length;
}SqList;

SqList L;

//顺序表初始化
int InitList(SqList &L)
{
    L.elem = new int[MAXSIZE];     
    if (!L.elem) exit(-1);               
    L.length = 0;                     
    return 1;
}
//顺序表插入 O(n)
int ListInsert(SqList &L, int i, int e)
{
    if(i < 1 || i > L.length + 1)               
        return 0;
    if(L.length == MAXSIZE)                 
        return 0;
    for(int j = L.length - 1; j >= i - 1; j--)
        L.elem[j + 1] = L.elem[j];        
    L.elem[i - 1] = e;                     
    L.length++;                           
    return 1; 
}
//顺序表表长
int ListLength(SqList L)
{
    return L.length;
}
//顺序表取值 O(1)
int GetElem(SqList L, int i, int &e)
{
    if(i < 1 || i > L.length)   
        return 0;
    e = L.elem[i - 1];          
    return e; 
}
int LocateElem(SqList &L, int e) {
    if(L.length < 1 || L.length > MAXSIZE)
        return -1;
    for (int i = 0; i < L.length;i++) {
        if (L.elem[i] == e)
            return i + 1;
    }
    return -1;
}
// ====================================================================

//2、顺序表销毁
int DestroyList(SqList &L)
{
    delete []L.elem; //TODO: 这是什么代码？
    L.elem = NULL;
    L.length = 0;
    return 1;
}

//3、顺序表清空
int ClearList(SqList &L)
{
    L.length = 0;
    return 1;
}

//4、顺序表空表
int ListEmpty(SqList L)
{
    if(L.length == 0)
        return 1;
    return 0;
}

//7、顺序表查找 O(n)
// int LocateElem(SqList L, int e)
// {//再顺序表中查找值为e的元素，返回其序号
//     for(int i = 0; i < L.length; i++)
//         if(L.elem[i] == e)
//             return i + 1;               //查找成功，返回序号i + 1
//     return 0;                       //查找失败，返回0
// }

//8、顺序表前驱
int PriorElem(SqList L, int cur_e, int &pre_e)
{
    for(int i = 0; i < L.length; i++)
        if(L.elem[i] == cur_e)
        {
            pre_e = L.elem[i - 1];
            return 1;
        }
    return 0; 
}

//9、顺序表后继
int NextElem(SqList L, int cur_e, int &next_e)
{
    for(int i = 0; i < L.length; i++)
        if(L.elem[i] == cur_e)
        {
            next_e = L.elem[i + 1];
            return 1;
        }
    return 0;   
}

//11、顺序表删除 O(n)
int ListDelete(SqList &L, int i)
{//在顺序表L中删除第i个元素， i值的合法范围是1<=i<=L.length
    if(i < 1 || i > L.length)
        return -1;                           //i值不合法
    for(int j = i; j <= L.length - 1; j++)
        L.elem[j - 1] = L.elem[j];              //被删除元素之后的元素前移
    L.length--;                                 //表长减1
    return 1;
}

//12、顺序表遍历 O(n)
int TraverseList(SqList L)
{
    for(int i = 0; i < L.length; i++)
    {
        if(i == L.length - 1)
            cout<<L.elem[i]<<'\n';
        else
            cout<<L.elem[i]<<' ';
    }
    return 1;
}

// ====================================================================

//实验1：顺序表的建立及运算
int main()
{
    SqList L;
    InitList(L);
    ListInsert(L, 1, 11);
    ListInsert(L, 2, 22);
    cout << L.elem[0]<<' '<< L.elem[1]<< '\n';
    cout << L.length << '\n';
    int e = -1;
    GetElem(L, 1, e);
    cout << e <<'\n';
    cout << LocateElem(L, 28) << '\n';
    ListDelete(L, 1);
    cout << "===================" << '\n';
    cout << L.elem[0] << L.elem[1];

    return 0;
}
