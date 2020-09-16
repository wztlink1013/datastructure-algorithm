package com.wztlink1013.al._递归法_;

import java.util.ArrayList;

/**
 * 子集问题
 */
public class SubSetting {
    ArrayList<Integer> x  = new ArrayList<Integer>();
    public static void main(String args[]) {
        Subsetting(3);
    }

    private void Subsetting(int n) {
        if (n > 0) {
            x.add(0);
            Subsetting(n - 1);
            x.remove(0);
            x.add(1);
            Subsetting(n - 1);
            x.remove(n - 1);
        }else {
            OutputOneSubsetBinary();
            OutputOneSubset();
            System.out.print("\n");
        }
    }

    private void OutputOneSubset() {
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

    private void OutputOneSubsetBinary() {
        int cnt = 0;
        System.out.printf("%03d: ", ++cnt);
        for (int i = x.size() - 1; i >= 0; i--)
            System.out.printf("%d", x.get(i));
    }
}