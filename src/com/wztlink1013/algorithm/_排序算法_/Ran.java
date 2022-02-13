package com.wztlink1013.algorithm._排序算法_;

import java.util.Random;

public class Ran {
    public static void main(String args[]) {
        System.out.println("种子1号测试：");
        for (int i = 0; i < 2; i++) {
            Random random = new Random(20);
            for (int j = 0; j < 10; j++) {
                System.out.print(" " + random.nextInt(100) + ", ");
            }
            System.out.println("");
        }
        System.out.println("种子2号测试：");
        for (int i = 0; i < 2; i++) {
            Random random = new Random(30);
            for (int j = 0; j < 10; j++) {
                System.out.print(" " + random.nextInt(100) + ", ");
            }
            System.out.println("");
        }

    }
}
