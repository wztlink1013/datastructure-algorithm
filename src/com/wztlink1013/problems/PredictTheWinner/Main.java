package com.wztlink1013.problems.PredictTheWinner;

public class Main {
    public static void main(String args[]){
        int [] number = {15, 123, 23, 242, 23, 54, 64, 12};
        System.out.println("成绩结果：" + PredictTheWinner(number));
    }
    public static boolean PredictTheWinner(int[] num){
        int first;
        if (num[0] >= num[num.length]){
            first = num[0];
        }else{
            first = num[num.length];
        }

        return true;
    }
}
