#include<bits/stdc++.h>
using namespace std;

#define MVNum 100
#define MaxInt 32767

typedef char VerTexType;
typedef int ArcType;

/**
 * 邻接矩阵存储形式
 */
typedef struct {
    /* data */
    VerTexType vexs[MVNum]; //顶点表
    ArcType arcs[MVNum][MVNum]; //邻接矩阵
    int vexnum, arcnum; //图的当前顶点和边数
}AMGraph;

/**
 * 确定v在G中的位置，即顶点数组的下标
 */
int LocateVex(AMGraph &G, char v) {
    for (int i = 0; i < G.vexnum;i++) {
        if (v == G.vexs[i]){
            return i;
        }
    }
}

/**
 * 创建无向网
 * 如果创建无向图   
 */
void CreateUDN(AMGraph &G) {
    // 采用邻接矩阵表示法，创建无向图G
    cout << "请输入顶点数和边数：" << endl;
    cin >> G.vexnum >> G.arcnum; //输入顶点数和边数
    // 初始化顶点
    for (int i = 0; i < G.vexnum;i++){
        cout << "请输入第" << i << "个顶点值" << endl;
        cin >> G.vexs[i];
    }
    // 初始化邻接矩阵的边的权值为最大值
    for (int i = 0; i < G.vexnum;i++) {
        for (int j = 0; j < G.vexnum;j++) {
            G.arcs[i][j] = MaxInt;
        }
    }
    // 构造邻接矩阵
    for (int k = 0; k < G.arcnum;k++) {
        cout << "请输入每条边所依附的顶点和权值：" << endl;
        char v1, v2;
        int w; //一条边所依附的顶点和权值
        cin >> v1 >> v2 >> w;
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        G.arcs[i][j] = w;
        G.arcs[j][i] = w;
    }
}

void Display(AMGraph &G) {
    for (int i = 0; i < G.vexnum;i++) {
        for (int j = 0; j < G.vexnum;j++) {
            cout << G.arcs[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    AMGraph test;
    // CreateUDN(test);
    Display(test);
}