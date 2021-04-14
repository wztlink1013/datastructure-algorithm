package com.wztlink1013.datastructure.java.arraylist;

/**
 * 作用：主函数测试接口
 */

public class Main {

    public static void main(String[] args) {
        ArrayList<Object> list  = new ArrayList<>();

        list.add(10);
        list.add(130);
        list.add(new Person(10, "Jack"));
        list.add(22);

        System.out.println("list: " + list.toString());
        System.out.println("size of list: " + list.size());
        System.out.println("130exit? : " + list.contains(130));
        System.out.println("get 2 of index element : " + list.get(2));

        Person a = new Person(10, "Jack");
        System.out.println("test indexOf of Person: " + list.indexOf(a));

    }

    static void test() {
        // int -> Integer

        // 所有的类，最终都继承java.lang.Object

        // new是向堆空间申请内存
        ArrayList<Person> persons  = new ArrayList<>();
        persons.add(new Person(10, "Jack"));
        persons.add(new Person(12, "James"));
        persons.add(new Person(15, "Rose"));
        persons.clear();
        persons.add(new Person(22, "abc"));

        System.out.println(persons);
        ArrayList<Integer> ints  = new ArrayList<>();
        ints.add(10);
        ints.add(10);
        ints.add(22);
        ints.add(33);
        System.out.println(ints);
    }
}


