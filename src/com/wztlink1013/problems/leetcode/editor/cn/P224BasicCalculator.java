package com.wztlink1013.problems.leetcode.editor.cn;

// P224.基本计算器
//实现一个基本的计算器来计算一个简单的字符串表达式的值。 
//
// 字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格 。 
//
// 示例 1: 
//
// 输入: "1 + 1"
//输出: 2
// 
//
// 示例 2: 
//
// 输入: " 2-1 + 2 "
//输出: 3 
//
// 示例 3: 
//
// 输入: "(1+(4+5+2)-3)+(6+8)"
//输出: 23 
//
// 说明： 
//
// 
// 你可以假设所给定的表达式都是有效的。 
// 请不要使用内置的库函数 eval。 
// 
// Related Topics 栈 数学 
// 👍 309 👎 0

import java.util.Stack;

public class P224BasicCalculator{
    public static void main(String[] args) {
        Solution solution = new P224BasicCalculator().new Solution();
        int key_1 = solution.calculate("7896979");
        int key_2 = solution.calculate("(23-2)-33+1111");
        System.out.println(key_1);
        System.out.println(key_2);
    }

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int calculate(String s) {
        Stack<Integer> stack_1 = new Stack<Integer>();
        int sum = 0;
        int sign = 1;
        int num = 0;

        for (int i=0;i<s.length();i++) {
            char ch = s.charAt(i);
            if (Character.isDigit(ch)) {
                num = 10 * num + (int) (ch - '0');
            } else if (ch == '+') {
                num = num * sign;
                sum = sum + num;
                sign = 1;
                num = 0;
            } else if (ch == '-') {
                num = num * sign;
                sum = sum + num;
                sign = -1;
                num = 0;
            } else if (ch == '(') {
                stack_1.push(sum);
                stack_1.push(sign);
                sum = 0;
                num = 0;
                sign = 1;
            } else if (ch == ')') {
                num = num * sign;
                sum = sum + num;
                sum = stack_1.pop() * sum;
                sum = sum + stack_1.pop();
                num = 0;
                sign = 1;
            }

        }
        sum = sum + sign * num;
        return sum;
    }}
//leetcode submit region end(Prohibit modification and deletion)

}