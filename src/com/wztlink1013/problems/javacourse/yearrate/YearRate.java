package com.wztlink1013.problems.javacourse.yearrate;

import java.util.Scanner;

public class YearRate {
    public static void main(String[] args){
        //Input money number\year date\month number
        System.out.println("Please enter number,w,n:");
        Scanner input = new Scanner(System.in);
        int number = input.nextInt();
        double w = input.nextDouble();
        int n = input.nextInt();
        double m = (w/(12*100)+1);
        double num = 0;

        //Calculation
        for (int i=0;i<n;i++){
            if(i == 0){
                num = number*m;
                continue;
            }
            num = (num+number)*m;
        }

        //Output year date
        System.out.printf("Money now is: %.3f",num);
    }
}

