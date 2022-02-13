#include<bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    // 遍历s并将其存入队列
    queue<char> que;
    int sum = 0;
    for (unsigned int i = 0; i < s.length(); i++) {
        que.push(s[i]);
    }
    // 各种判断条件
    while (! que.empty()) {
        char temp = que.front();
        // 单引号和双引号的区别？
        if (temp == 'I') {
            que.pop();
            if (! que.empty()) {
                if (que.front() == 'V'){
                    sum = sum + 4;
                    que.pop();
                } else if (que.front() == 'X'){
                    sum = sum + 9;
                    que.pop();
                } else {
                    sum = sum + 1;
                }
            } else {
                sum = sum + 1;
            }
        } else if(temp == 'X') {
            que.pop();
            if (! que.empty()) {
                if (que.front() == 'L'){
                    sum = sum + 40;
                    que.pop();
                } else if (que.front() == 'C'){
                    sum = sum + 90;
                    que.pop();
                } else {
                    sum = sum + 10;
                }
            } else {
                sum = sum + 10;
            }
        } else if ( temp == 'C'){
            que.pop();
            if (! que.empty()) {
                if (que.front() == 'D'){
                    sum = sum + 400;
                    que.pop();
                } else if (que.front() == 'M'){
                    sum = sum + 900;
                    que.pop();
                } else {
                    sum = sum + 100;
                }
            } else {
                sum = sum + 100;
            }
        } else if (temp == 'V'){
            sum = sum + 5;
            que.pop();
        } else if (temp == 'L'){
            sum = sum + 50;
            que.pop();
        } else if (temp == 'D'){
            sum = sum + 500;
            que.pop();
        } else if (temp == 'M'){
            sum = sum + 1000;
            que.pop();
        }
        
    }
    return sum;
}

int main () {
    string s = "MCMXCIV";
    cout<<"sum："<<romanToInt(s);
}