package com.wztlink1013.algorithm._排序_;
/**
 * fun：测试冒泡排序
 * */

import java.util.Random;

public class bubbleSort {
    public static void bubble(int[] data) {
        for (int i = 0; i < data.length - 1; i++) {
            for (int j = 0; j < data.length - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    int tmp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = tmp;
                }
            }
        }
    }
    public static void main(String args[]) {
        int n = 800000;
        int [] arr_1 = new int[n];
//        for (int k = 0; k < 1; k++) {
//            System.out.println("冒泡排序前：");
            Random random = new Random(20);
            for (int j = 0; j < n; j++) {
//                System.out.print(" " + random.nextInt(100) + ", ");
                arr_1[j] = random.nextInt(100);
//            }
//            System.out.println("");
        }
        bubble(arr_1);
//        System.out.println("冒泡排序后：");

//        for (int i=0;i<arr_1.length;i++)
//            System.out.print(" " + arr_1[i]+", ");
//        System.out.println(" ");
        Times.test("当n = " + n + "时候的耗费时间", new Times.Task() {
            public void execute() {
                bubble(arr_1);
            }
        });
    }
}
