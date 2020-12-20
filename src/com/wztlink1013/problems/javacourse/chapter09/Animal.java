package com.wztlink1013.problems.javacourse.chapter09;


class Dog
{
    Dog (int i)
    {
        System.out.println("Dog(" + i + ")");
    }
    static Cat cat9 = new Cat(30);
}

class Cat
{
    Cat (int j)
    {
        Dog dog1 = new Dog(10);
        System.out.println("Cat(" + j + ")");
    }
    Dog dog2 = new Dog(20);
}

public class Animal
{
    Dog dog2 = new Dog(2);
    Cat cat2 = new Cat(3);
    Animal (int k)
    {
        System.out.println("Animal(" + k + ")");
    }
    public static void main(String[] args)
    {
        Dog dog = new Dog(5);
        Cat cat = new Cat(5);
    }
}
