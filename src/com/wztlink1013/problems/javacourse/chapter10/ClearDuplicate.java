package com.wztlink1013.problems.javacourse.chapter10;


import java.util.ArrayList;
import java.util.Scanner;

public class ClearDuplicate {
    public static void main(String[] args) {

//	输入值且存储在list中
        System.out.print("Enter ten integers: ");
        ArrayList<Integer> list = new ArrayList<>();

        Scanner input = new Scanner(System.in);
        for (int i = 0; i < 10; i++) {
            list.add(input.nextInt());
        }

        clearDuplicate(list);

//	打印清除后的list
        System.out.print("The distinct integersare: ");
        for (int i = 0; i < list.size(); i++)
            System.out.print(list.get(i) + " ");
        input.close();
    }

    //	fun：清除list中重复的值
    public static void clearDuplicate(ArrayList<Integer> list) {
        ArrayList<Integer> temp = new ArrayList<Integer>();
        for (int i = 0; i < list.size(); i++)
            if (!temp.contains(list.get(i)))
                temp.add(list.get(i));
        list.clear();
        for (int i = 0; i < temp.size(); i++)
            list.add(temp.get(i));
    }
}
