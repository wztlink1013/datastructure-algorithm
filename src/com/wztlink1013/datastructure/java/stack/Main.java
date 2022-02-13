package com.wztlink1013.datastructure.java.stack;

public class Main {

    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        stack.push(11);
        stack.clear();
        stack.push(22);
        stack.push(33);
        stack.push(44);

        System.out.println(stack.size());
        System.out.println(stack.isEmpty());

        while (!stack.isEmpty()) {
            System.out.println(stack.pop());
        }
    }

}