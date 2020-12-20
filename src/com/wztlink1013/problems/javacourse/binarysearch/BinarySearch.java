package com.wztlink1013.problems.javacourse.binarysearch;


import java.util.Scanner;

public class BinarySearch {
    public static void main(String[] args) {

        int[] array = { 1, 3, 3, 3, 3, 6, 6, 8, 8, 8, 10};
        Scanner input = new Scanner(System.in);
        System.out.print("Please enter the number :");
        int number = input.nextInt();

        if (args[0].equals("1")) {
            if (Exist(array,number) == -1)
                System.out.println("The position of" + "  " + Binaryfun1(array, 0, array.length - 1, number));
            else
                System.out.println("There is no queried value in the array, and the inserted array index is:"+Exist(array,number));
        }
        else if (args[0].equals("2")) {
            if (Exist(array,number) == -1)
                System.out.println("The position of" + "  " + Binaryfun2(array, 0, array.length - 1, number));
            else
                System.out.println("There is no queried value in the array, and the inserted array index is:"+Exist(array,number));
        }

        input.close();
    }

    // See if the selected number is in the array
    private static int Exist(int[] arr, int number) {
        for (int i=0;i<arr.length;i++){
            if (number > arr[i] && number <arr[i+1])
                return i+1;
        }
        return -1;
    }

    // Binaryfun1
    private static int Binaryfun1(int[] arr, int low, int high, int number) {
        //binary
        while (high >= low) {
            int mid = (low + high) / 2;
            if (arr[mid] == number) {
                //ahead
                int count = 0;
                while (arr[mid-(count+1)] == number)
                    count = count +1;

                return mid-count;
            }
            if (arr[mid] > number) {
                return Binaryfun1(arr, low, mid - 1, number);
            }
            if (arr[mid] < number) {
                return Binaryfun1(arr, mid + 1, high, number);
            }
        }
        return -1;
    }

    // Binaryfun2
    private static int Binaryfun2(int[] arr, int low, int high, int number) {
        //binary
        while (high >= low) {
            int mid = (low + high) / 2;
            if (arr[mid] == number) {
                //later
                int count = 0;
                while (arr[mid+(count+1)] == number)
                    count = count +1;

                return mid+count;
            }
            if (arr[mid] > number) {
                return Binaryfun2(arr, low, mid - 1, number);
            }
            if (arr[mid] < number) {
                return Binaryfun2(arr, mid + 1, high, number);
            }
        }
        return -1;
    }

}

