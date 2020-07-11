/**
 * author:wztlink1013
 * fun:算是第一次正式刷题吧：fibonacci
 */
package com.wztlink1013.ds.times.lc509fibonacci;

public class Fibonacci {
    // TODO: for循环实现
    public static int fib(int n) {
        if (n <= 1) return n;
        int first = 0;
        int second = 1;
        for (int i = 0; i < n - 1; i++) {
            int sum = first + second;
            first = second;
            second = sum;
        }
        return second;
    }
    // TODO: 递归实现O(2^n)
    public static int fib1(int n) {
        if (n <= 1) return n;
        return fib1(n - 1) + fib1(n - 2);
    }
    // TODO: 首尾实现
    public static int fib3(int n) {
        if (n <= 1) return n;
        int first = 0;
        int second = 1;
        while (n-- > 1) {
            second += first;
            first = second - first;
        }
        return second;
    }

    // 主函数测试
    public static void main(String[] args){
        System.out.println(fib(13));
    }
}