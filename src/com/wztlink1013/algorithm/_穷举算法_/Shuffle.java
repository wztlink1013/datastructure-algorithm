package com.wztlink1013.algorithm._穷举算法_;

/**
* 作用：洗牌算法
**/

import java.util.Scanner;
import java.util.Random;

public class Shuffle {
    public static void main(String args[]){

        // 放n个排好序的数字数组
        System.out.println("请输入“牌”的总数：");
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int [] arr = new int[n];
        for (int i=1;i<=n; i++){
            arr[i-1] = i;
        }

        // todo: for循环从尾到头
        for (int i = n-1;i>0;i--) {
            // todo: 生成随机数number
            Random r = new Random();
            int number = r.nextInt(n);
            // todo: 值交换
            swap(arr[number],arr[i]);
        }

        System.out.print("洗牌之后的值为：");
        for (int i = 0;i<n;i++){
            System.out.print(arr[i]+",");
        }
    }
    public static void swap(int i, int j){
        int k;
        k = i;
        i = j;
        j = k;
    }

}
