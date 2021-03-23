#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 100

typedef struct 
{
    int *arr;
    int length;
}SqList;

SqList L;

void InitList(SqList &L)
{
    L.arr = new int[MAXSIZE];     
    if (!L.arr) exit(-1);               
    L.length = 0;                     
}

void ListInsert(SqList &L) {
    cout << "请输入元素个数n：";
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> L.arr[i];
        L.length++;
    }
}
void TraverseList(SqList &L) {
    cout << "该顺序表元素遍历结果为：";
    for (int i = 0; i < L.length;i++) {
        cout << L.arr[i] << ' ';
    }
    cout << "\n";
}
void NumberMax (SqList &L){
    cout << "该顺序表最大值为：";
    int max = L.arr[0];
    for (int i = 0; i < L.length;i++) {
        if(L.arr[i]>max)
            max = L.arr[i];
    }
    cout << max<<"\n";
}
void InsertOneElement (SqList &L) {
    cout << "请分别输入在n位置插入的e值：";
    int n;
    int e;
    cin >> n >> e;
    for (int i = L.length - 1; i >= n-1;i--){
        L.arr[i + 1] = L.arr[i];
    }
    L.arr[n-1] = e;
    L.length++;
    cout << "\n"<<"插入值之后的顺序表为：";
    TraverseList(L);
}
void DeleteOneElement (SqList &L) {
    cout << "请输入要删除n位置的n值：";
    int n;
    cin >> n;
    for (int i = 0; i < L.length;i++){
        if (i>=n-1){
            L.arr[i] = L.arr[i + 1];
        }
    }
    L.length--;
    cout << "\n"<<"删除值之后的顺序表为：";
    TraverseList(L);
}
void IncrList (SqList &L) {
    cout << "升序之后的顺序表为：";
    for (int i = 0; i < L.length;i++){
        for (int j = 0; j < L.length;j++){
            if (L.arr[j]>L.arr[i]) {
                int temp;
                temp = L.arr[j];
                L.arr[j] = L.arr[i];
                L.arr[i] = temp;
            }
        }
    }
    TraverseList(L);
}

void ReverseList (SqList &L) {
    cout << "逆序之后……";
    for (int i = 0; i < L.length / 2;i++){
        int temp;
        temp = L.arr[i];
        L.arr[i] = L.arr[L.length-i-1];
        L.arr[L.length-i-1] = temp;
    }
    TraverseList(L);
}
int main () {
    SqList test;
    InitList(test);//1
    ListInsert(test);//1
    TraverseList(test);//1
    NumberMax(test);//2
    InsertOneElement(test);//3
    DeleteOneElement(test);//4
    IncrList(test);//5
    ReverseList(test);//6
}