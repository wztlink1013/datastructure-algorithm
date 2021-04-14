package com.wztlink1013.datastructure.java.stack;


import com.wztlink1013.datastructure.java.stack.list.ArrayList;
import com.wztlink1013.datastructure.java.stack.list.List;

public class Stack<E> {
    private List<E> list = new ArrayList<>();

    public void clear() {
        list.clear();
    }

    public int size() {
        return list.size();
    }

    public boolean isEmpty() {
        return list.isEmpty();
    }

    public void push(E element) {
        list.add(element);
    }


    public E pop() {
        return list.remove(list.size() - 1);
    }


    public E top() {
        return list.get(list.size() - 1);
    }
}

