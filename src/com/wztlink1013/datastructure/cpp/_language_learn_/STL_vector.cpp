#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int main() {
    vector<int> a(10, 0);
    a[2] = 2;
    a[6] = 234;
    for (unsigned int i = 0; i < a.size();i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    cout << "=========================="
         << "\n";
    // 二维数组10*5
    vector < vector<int>> b(10, vector<int>(5, 0));
    b[3][4] = 32;
    b[2][4] = 1224;
    // b.size()获取行向量大小
    for (unsigned int i = 0; i < b.size();i++) {
        for (unsigned int j = 0; j < b[i].size();j++) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "==测试queue========================"
        << "\n";
    queue<int> Q;
    Q.push(12);
    Q.push(23);
    cout << Q.front() << " " << Q.front()<<" "<<Q.empty()<<" "<<Q.size();
}