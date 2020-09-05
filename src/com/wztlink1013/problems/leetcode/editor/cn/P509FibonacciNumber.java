package com.wztlink1013.problems.leetcode.editor.cn;

//斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是： 
//
// F(0) = 0,   F(1) = 1
//F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
// 
//
// 给定 N，计算 F(N)。 
//
// 
//
// 示例 1： 
//
// 输入：2
//输出：1
//解释：F(2) = F(1) + F(0) = 1 + 0 = 1.
// 
//
// 示例 2： 
//
// 输入：3
//输出：2
//解释：F(3) = F(2) + F(1) = 1 + 1 = 2.
// 
//
// 示例 3： 
//
// 输入：4
//输出：3
//解释：F(4) = F(3) + F(2) = 2 + 1 = 3.
// 
//
// 
//
// 提示： 
//
// 
// 0 ≤ N ≤ 30 
// 
// Related Topics 数组 
// 👍 153 👎 0

public class P509FibonacciNumber{
    public static void main(String[] args) {
        Solution solution = new P509FibonacciNumber().new Solution();
        
    }

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    // TODO: for循环实现
    public int fib(int N) {
        if (N <= 1) return N;
        int first = 0;
        int second = 1;
        for (int i = 0; i < N - 1; i++) {
            int sum = first + second;
            first = second;
            second = sum;
        }
        return second;
    }
//    // TODO: 递归实现O(2^n)
//    public int fib1(int n) {
//        if (n <= 1) return n;
//        return fib1(n - 1) + fib1(n - 2);
//    }
//    // TODO: 首尾实现
//    public int fib3(int n) {
//        if (n <= 1) return n;
//        int first = 0;
//        int second = 1;
//        while (n-- > 1) {
//            second += first;
//            first = second - first;
//        }
//        return second;
//    }
}
//leetcode submit region end(Prohibit modification and deletion)

}