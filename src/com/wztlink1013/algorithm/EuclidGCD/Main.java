package com.wztlink1013.algorithm.EuclidGCD;
import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner input = new Scanner(System.in);

        System.out.println("请输入两个大于零的自然数：");
        int a = input.nextInt();
        int b = input.nextInt();
        System.out.println(a + "和" + b + "两个数的GCD值为：" + GCD(a,b));
    }
    public static int GCD(int i, int j){
        int r;
        while (j != 0){
            r = i%j;
            i = j;
            j = r;
            System.out.println("a="+i+"；b="+j+"；r="+r);
        }
        return i;
    }
}
