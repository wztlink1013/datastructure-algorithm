package com.wztlink1013.problems.javacourse.chapter10;


import java.util.ArrayList;

public class QueueOflntegers<T> {
    private ArrayList<T> arrayList;

    //	入队
    public void add(T t) {
        if (arrayList == null) {
            arrayList = new ArrayList<>();
        }
        arrayList.add(t);
    }

    //  出队-首元素
    public T removeH() {
        if (arrayList != null && arrayList.size() > 0) {
            return arrayList.remove(0);
        }
        return null;
    }

    //  出队-尾元素
    public T removeT() {
        if (arrayList != null && arrayList.size() > 0) {
            return arrayList.remove(arrayList.size());
        }
        return null;
    }

    //  判断队列元素是否为空
    public int size() {
        return arrayList == null ? 0 : arrayList.size();
    }

}
