#include<bits/stdc++.h>
typedef int Status;
typedef int SElemType;
#define OVERFLOW -1
#define ERROR 0
#define OK 1
#define MAXSIZE 100

using namespace std;
/**
 * 顺序栈
 * 
 * 顺序栈的基本操作：初始化、入栈、出栈、取栈顶元素
 */

/* 顺序栈的存储形式 */
typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

/* 初始化 */
Status InitSqStack(SqStack &stack) {
    // 为栈分配容量
    stack.base = new int[MAXSIZE];
    // 分配失败返回失败值
    if (!stack.base) {
        return OVERFLOW;
    }
    // 让栈顶地址初始为栈底地址
    stack.top = stack.base;
    // 初始化容量
    stack.stacksize = MAXSIZE;
    return OK;
}

/* 入栈 */
Status Push(SqStack &stack, SElemType e) {
    if (stack.top - stack.base == stack.stacksize) {
        return OVERFLOW;
    }
    *stack.top = e; // 先在top位置赋值
    stack.top++; // 将top地址++
    return OK;
}

/* 出栈 */
Status Pop(SqStack &stack) {
    // 空栈返回异常
    if (stack.top == stack.base) {
        return OVERFLOW;
    }
    stack.top--; // 栈顶地址减1
    return *stack.top; // 返回此时“栈顶”元素
}

/* 取栈顶元素 */
Status GetTop (SqStack &stack) {
    // 空栈返回异常
    if (stack.top == stack.base) {
        return OVERFLOW;
    }
    // stack.top--; // 栈顶地址减1，这是和出栈的区别
    return *(stack.top-1); // 返回此时“栈顶”元素
}

int main() {
    SqStack test;
    InitSqStack(test);
    Push(test, 10);
    Push(test, 15);
    Push(test, 20);
    cout << GetTop(test)<<" "<< GetTop(test)<<" "<< GetTop(test)<<" "<<"\n";
    cout << Pop(test)<<" "<< Pop(test)<<" "<< Pop(test)<<" "<<"\n";
}