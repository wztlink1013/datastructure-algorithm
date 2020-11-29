package com.wztlink1013.algorithm._穷举算法_;
/**
* 作用：素性测试
* */
import java.util.Scanner;

public class Prime {
    public static void main(String args[]) {
        System.out.println("输入一个将要判断是否为素数的数：");
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for (int i = 2;i*i < n;i++) {
            if (n%i == 0){
                System.out.println(n + "不是素数");
                break;
            }

        }
    }
}
