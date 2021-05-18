#include <bits/stdc++.h>
using namespace std;

#define MVNum 100
#define MaxInt 32767

typedef char VerTexType;
typedef int OtherInfo;

/**
 * 邻接表存储
 */

/**
 * 存储结构
 */
typedef struct ArcNode {                      //边结点                    
    int adjvex;                             //该边所指向的结点的位置
    struct ArcNode *nextarc;                //指向下一条边的指针
    OtherInfo info;                         //和边相关的其他信息
}ArcNode;

typedef struct VNode {                        //顶点信息
    VerTexType data;                        //数据域，存放顶点vi的名称或其他有关信息
    ArcNode *firstarc;                      //指向第一条依附该顶点的边的指针
}VNode, AdjList[MVNum];                     //AdjList表示邻接表的类型

typedef struct {
    AdjList vertices;
    int vexnum, arcnum;                     //图当前的顶点数和边数
}ALGragh;                                   //邻接表（Adjacency List）


/**
 * 找到v顶点在图中的位置
 */
int LocateVex(ALGragh &G, char v) {
    for (int i = 0; i < G.vexnum;i++) {
        if (v == G.vertices[i].data) {
            return i;
        }
    }
}

/**
 * 邻接表创建无向图
 */
void CreateUDG(ALGragh &G) {
    cin >> G.vexnum >> G.arcnum; // 邻接表的顶点数和边数
    for (int i = 0; i < G.vexnum;i++) {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    
    for (int k = 0; k < G.arcnum;k++) {
        char v1, v2;
        cin >> v1 >> v2;
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        ArcNode *p1 = new ArcNode;
        p1->adjvex = j;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;
        ArcNode *p2 = new ArcNode;
        p2->adjvex = i;
        p2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p1;
    }
}