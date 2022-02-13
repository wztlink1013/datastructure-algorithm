#include<bits/stdc++.h>
using namespace std;
typedef int Status;
typedef char TElemType;
#define OVERFLOW -1
#define ERROR 0
#define OK 1
char ch;
int cnt;

/**
 * 采用二叉链表的存储形式
 */
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


/**
 * 创建一棵二叉树
 */
void CreateBiTree(BiTree &T) {
    //按先序次序输入二叉树中结点的值，创建二叉链表表示的二叉树T
    TElemType ch;
    cin>>ch;
    if(ch == '#'){//递归结束，建空树
        T = NULL;
    } else {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }     
        
}

/**
 * 先序遍历
 */
void PreOrderTraverse(BiTree &T)
{//先序遍历二叉树T的递归算法
    if(T)                               //若二叉树非空 
    {
        cout << T->data << " ";                  //访问根结点 
        PreOrderTraverse(T->lchild);     //中序遍历左子树 
        PreOrderTraverse(T->rchild);     //中序遍历右子树
    }
}


/**
 * 中序遍历
 */
void InOrderTraverse(BiTree &T) {
    if (T) {
        InOrderTraverse(T->lchild);
        cout << T->data << " ";
        InOrderTraverse(T->rchild);
    }
}


/**
 * 后序遍历
 */
void PostOrderTraverse(BiTree &T)
{//后序遍历二叉树T的递归算法
    if(T)                               //若二叉树非空 
    {
        PostOrderTraverse(T->lchild);   //中序遍历左子树 
        PostOrderTraverse(T->rchild);   //中序遍历右子树
        cout << T->data << " ";                 //访问根结点 
    }
}

/**
 * 统计二叉树中节点个数
 */
int NodeCount (BiTree &T) {
    if (T == NULL) {
        return 0;
    } else {
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
    }
}

/**
 * 二叉树中叶结点个数
 */
int LeavesCount (BiTree &T) {
    if (T == NULL) {
        return 0;
    } else if (T->lchild == NULL && T->rchild == NULL) {
        return LeavesCount(T->lchild) + LeavesCount(T->rchild) + 1;
    }
    else {
        return LeavesCount(T->lchild) + LeavesCount(T->rchild);
    }
}

int main() {
    BiTree test = new BiTNode;
    cout << "请输入一个字符串以生成二叉树：";
    CreateBiTree(test);
    cout <<"\n"<< "先序遍历结果：";
    PreOrderTraverse(test);
    cout <<"\n"<< "中序遍历结果：";
    InOrderTraverse(test);
    cout <<"\n"<< "后序遍历结果：";
    PostOrderTraverse(test);
    cout <<"\n"<< "二叉树结点个数："<<NodeCount(test);
    cout <<"\n"<< "二叉树叶结点个数："<<LeavesCount(test);
}

