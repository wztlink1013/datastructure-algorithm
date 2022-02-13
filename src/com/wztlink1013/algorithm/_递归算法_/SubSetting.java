package com.wztlink1013.algorithm._递归算法_;

import java.util.ArrayList;

/**
 * 子集问题
 */
public class SubSetting {
    static ArrayList<Integer> x  = new ArrayList<Integer>();
    static int cnt = 0;

    public static void main(String args[]) {
        int n = 23;
        Times.test("当n = " + n + "时候的耗费时间", new Times.Task() {
            public void execute() {
                Subsetting(n);
            }
        });
    }

    private static void Subsetting(int n) {
        if (n > 0) {
            x.add(0);
            Subsetting(n - 1);
            x.remove(x.size() - 1);
            x.add(1);
            Subsetting(n - 1);
            x.remove(x.size() - 1);
        }else {
            OutputOneSubsetBinary();
            OutputOneSubset();
            System.out.print("\n");
        }
    }

    private static void OutputOneSubset() {
        System.out.printf("; {");
        int k = 0;
        for (int i = x.size() - 1; i >=0; i--) {
            if (x.get(i) == 1) {
                if (k > 0)
                    System.out.printf(",");
                System.out.printf("%d", x.size() - i);
                k++;
            }
        }
        System.out.printf("}");
    }

    private static void OutputOneSubsetBinary() {
        System.out.printf("%010d: ", ++cnt);
        for (int i = x.size() - 1; i >= 0; i--)
            System.out.printf("%d", x.get(i));
    }
}