package com.wztlink1013.algorithm.sort;
/**
 * fun：测试插入排序
 * */

import java.util.Random;

public class InsertSort {
    public static void insert(int[] a) {
        int i, j, insertNote;
        for (i = 1; i < a.length; i++) {
            insertNote = a[i];
            j = i - 1;
            while (j >= 0 && insertNote < a[j]) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = insertNote;
        }
    }
    public static void main(String args[]) {
        int n = 10000000;
        int [] arr_1 = new int[n];
//        for (int k = 0; k < 1; k++) {
//            System.out.println("插入排序前：");
            Random random = new Random(20);
            for (int j = 0; j < n; j++) {
//                System.out.print(" " + random.nextInt(100) + ", ");
                arr_1[j] = random.nextInt(100);
            }
//            System.out.println("");
//        }
        insert(arr_1);
//        System.out.println("插入排序后：");
//        for (int i=0;i<arr_1.length;i++)
//            System.out.print(" " + arr_1[i]+", ");
//        System.out.println(" ");
        Times.test("当n = " + n + "时候的耗费时间", new Times.Task() {
            public void execute() {
                insert(arr_1);
            }
        });
    }
}
