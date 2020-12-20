package com.wztlink1013.problems.javacourse.graph;

import java.util.Scanner;

class ArcNode{
    int vertex; // 定义数据域
    ArcNode next = null; // 定义指针域
}

class VNode{
    String vdata = new String();
    ArcNode next = null;
}

public class CreatGraph {

    public static void main(String[] args) {
        int[][] adjMatrix = new int[][]{
                {0,1,0,1,0,0,0,0},
                {1,0,1,0,0,0,0,0},
                {0,1,0,1,1,0,0,0},
                {1,0,1,0,0,0,0,0},
                {0,0,1,0,0,1,1,0},
                {0,0,0,0,1,0,0,1},
                {0,0,0,0,1,0,0,1},
                {0,0,0,0,0,1,1,0}};
        Scanner scan = new Scanner(System.in);
        System.out.print("输入1/2分别选择前插法/后插法操作！ \n");
        int choice = scan.nextInt();
        VNode[] listNodes = list(adjMatrix, choice);
        printNodes(listNodes);
        scan.close();
    }

    //		转换
    public static VNode[] list(int[][] adjMatrix, int choice) {
        int len = adjMatrix.length;
        VNode[] listNode = new VNode[len];
        ArcNode q;

//		前插法
        if (choice == 1) {
            for (int i = 0;i<len;i++) {
                listNode[i] = new VNode();
                listNode[i].vdata = "->" + (i+1);
                for (int j = 0;j<len;j++) {
                    if (adjMatrix[i][j] == 1) {
                        ArcNode nextNode = new ArcNode();
                        nextNode.vertex = j;
                        if (listNode[i].next == null) {
                            listNode[i].next = nextNode;
                        } else {
                            q = listNode[i].next;
                            listNode[i].next = nextNode;
                            nextNode.next = q;
                        }
                    }
                }
            }
        }

//		后插法
        if (choice == 2) {
            for (int i = 0;i<len;i++) {
                listNode[i] = new VNode();
                listNode[i].vdata = "->" + (i+1);
                q = listNode[i].next;
                for (int j = 0;j<len;j++) {
                    if (adjMatrix[i][j] == 1) {
                        ArcNode nextNode = new ArcNode();
                        nextNode.vertex = j;
                        if (listNode[i].next == null) {
                            listNode[i].next = nextNode;
                        } else {
                            q.next = nextNode;
                        }
                        q = nextNode;
                    }
                }
            }
        }
        return listNode;
    }

    //	打印连接表
    public static void printNodes (VNode[] adj) {
        ArcNode q;
        for (int i=0;i<adj.length;i++) {
            System.out.print(i+adj[i].vdata);
            q = adj[i].next;
            while (q!=null) {
                System.out.print(q.vertex);
                q = q.next;
            }
        }
    }
}

