#include<vector>
#include<list>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 笔记：https://www.wztlink1013.com/blog/porzdi/
 */
template <class T1, class T2>
void sum(T1 x, T2 y) {
    cout << sizeof(x + y);
}
template <class T>
T result(list<T> L, T key) {
    typename list<T>::iterator p;
    int count = 0;
    for (p = L.begin();p!=L.end();p++) {
        if (*p == key) {
            break;
        }
        p++;
        if (p == L.end()) {
            count = -1;
            break;
        }
        p--;
        count++;
    }
    return count;
}



int main() {
    cout << "==测试vector============================="<< "\n";
    cout << "测试一维数组" << endl;
    vector<int> a(10, 0);
    a[2] = 2;
    a[6] = 234;
    for (unsigned int i = 0; i < a.size();i++) 
        cout << a[i] << " ";
    cout << "\n"<<"\n";
    cout << "测试二维数组" << endl;
    // 创建并初始化二维数组10*5（所有元素都为0）
    vector < vector<int>> b(10, vector<int>(5, 0));
    // 修改其中的值
    b[3][4] = 32;
    b[2][4] = 1224;
    // b.size()获取行向量大小
    for (unsigned int i = 0; i < b.size();i++) {
        for (unsigned int j = 0; j < b[i].size();j++) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "==测试queue============================="<< "\n";
    queue<int> Q;
    Q.push(12);
    Q.push(23);
    cout << Q.front()<<endl;
    Q.pop();
    cout <<"空了吗："<< Q.empty()<<"size数量："<<Q.size()<<endl;
    cout << Q.front()<<endl;
    Q.pop();
    cout <<"空了吗："<< Q.empty()<<"size数量："<<Q.size()<<endl;
    cout << "==测试STL中的函数模板============================="<< "\n";
    sum('1', 99.0);
    list<int> L = {2, 5, 2, 7, 4, 7, 33, 5};
    cout<< "\n课后编程题第一题："<<result(L, 50);
    
}