package com.wztlink1013.ds.linkedlist;

public class T729MyCalendar {
    public static void main(String[] args) {
        System.out.println("value:");
        MyCalendar cal = new MyCalendar();
        boolean param_1 = cal.book(10, 20);
        System.out.println(param_1);
    }

}

class MyCalendar {

    int [] month = new int[30];
    public MyCalendar() {


    }

    public boolean book(int start, int end) {
        boolean p = true;


        if (month[start] == 1) {
            p = false;
        }

        else {
            while (p) {
                int i = start;
                month[i] = 1;
                if (month[i+1] == 1) {
                    return p = false;
                }
                i = i+1;
            }
        }
        return p;
    }

}


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */
