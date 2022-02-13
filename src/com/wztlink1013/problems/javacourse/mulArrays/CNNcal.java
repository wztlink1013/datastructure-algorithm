package com.wztlink1013.problems.javacourse.mulArrays;

import java.util.Scanner;

public class CNNcal {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Please input StepLenght k��");
        int k = input.nextInt();
        int[][] img = {
                {3,0,1,5,0,3,0,3},
                {2,6,2,4,3,0,3,0},
                {2,4,1,0,6,1,4,1},
                {3,0,1,5,0,3,0,2},
                {2,6,2,4,3,2,3,0},
                {2,4,1,0,6,2,1,1},
                {2,6,2,4,4,0,3,6},
                {2,4,1,0,6,1,6,1}
        };
        int[][] kernel= {
                {-1,0,1},
                {-2,0,2},
                {-1,0,1}
        };

        // display CDD
        System.out.println("The result after calculation is:");
        calculate(img,kernel,k);
        input.close();

    }
    public static void calculate(int[][] img, int[][] kernel,int k) {

        int row = (img.length-kernel.length)/k+1;
        int col = (img[0].length-kernel[0].length)/k+1;
        int[][] result = new int[row][col];

        int m=0;
        for(int i = 0; i < row;i++) {
            int n=0;
            for(int j = 0;j < col;j++) {
                for(int i1 = 0;i1 < kernel.length;i1++) {
                    for(int j1 = 0;j1<kernel[0].length;j1++) {
                        result[i][j] += img[i1+m][j1+n]*kernel[i1][j1];
                    }
                }
                System.out.print(result[i][j]+" ");
                n+=k;
            }
            m+=k;
            System.out.println(" ");

        }

    }

}

