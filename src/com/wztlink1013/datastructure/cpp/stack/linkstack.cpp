#include<bits/stdc++.h>
typedef int Status;
typedef int SElemType;
#define OVERFLOW -1
#define ERROR 0
#define OK 1
#define MAXSIZE 100

using namespace std;
/**
 * 链栈
 * 
 * 链栈的基本操作：初始化、入栈、出栈、取栈顶元素
 */

/* 链栈的存储形式 */
typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;

/**
 * 初始化
 * 不设头结点
 */
Status InitLinkStack(LinkStack &stack) {
    stack = NULL; // 栈顶元素置空
    return OK;
}

/* 入栈 */
Status Push(LinkStack &stack, SElemType e) {
    // 不能用LinkStack这样声明结点变量，需要new一个内存空间
    LinkStack temp = new StackNode;
    temp->data = e;
    temp->next = stack;
    stack = temp;
    return OK;
}

/* 出栈 */
Status Pop (LinkStack &stack) {
    SElemType i = stack->data;
    stack = stack->next;
    return i;
}

/* 取栈顶元素 */
Status GetTop (LinkStack &stack) {
    return stack->data;
}


int main() {
    LinkStack test;
    InitLinkStack(test);
    Push(test, 10);
    Push(test, 15);
    Push(test, 20);
    cout << GetTop(test)<<" "<< GetTop(test)<<" "<< GetTop(test)<<" "<<"\n";
    cout << Pop(test)<<" "<< Pop(test)<<" "<< Pop(test)<<" "<<"\n";
}