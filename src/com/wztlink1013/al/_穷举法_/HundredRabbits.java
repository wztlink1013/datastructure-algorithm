package com.wztlink1013.al._穷举法_;
/**
* 作用：百元买百兔
* */
public class HundredRabbits {
    public static void main(String args[]) {
//        原始穷举
//        for (int x = 1; x<100; x++) {
//            for (int y = 1; y<100; y++) {
//                for (int z = 1; z<100; z++) {
//                    if ((15 * x + 9 * y + z == 300) && (x + y + z == 100) && (z%3 == 0)) {
//                        System.out.println("x=" + x + "y=" + y + "z=" + z);
//                    }
//                }
//            }
//        }
//        优化穷举
        for (int x = 1; x<20; x++) {
            for (int y = 1; y<33; y++) {
                int z = 100 - x -y;
                if ((15 * x + 9 * y + z == 300) && (x + y + z == 100) && (z%3 == 0)) {
                    System.out.println("x=" + x + "y=" + y + "z=" + z);
                }
            }
        }
    }
}
