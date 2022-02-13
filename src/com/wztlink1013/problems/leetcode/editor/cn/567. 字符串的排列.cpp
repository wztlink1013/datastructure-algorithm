#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // 把字符串里面的字符进行全排列枚举

        // 将所有的枚举串和目标串进行比较
        // 只要结果里面有true则表示匹配成功

    }
    bool result(string s1, string s2) {
        // BF算法，字符串匹配算法
        for (unsigned int i = 0; i < s2.length();i++) {
            if ((s1[0] == s2[i]) && (s1.length()<=s2.length()-i)) {
                for (unsigned int j = 0; j <= s1.length();j++) {
                    if (s1.length() - j == 0) {
                        return true;
                    }
                    if (s1[j] == s2[i+j]){
                        continue;
                    } else {
                        break;
                    }
                }
            }
        }
        return false;
    }
};


int main() {
    Solution result;
    cout << boolalpha << result.checkInclusion("aub", "agedsabcd");
}