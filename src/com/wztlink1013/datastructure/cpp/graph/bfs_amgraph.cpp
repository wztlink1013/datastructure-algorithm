#include<bits/stdc++.h>
using namespace std;

#define MVNum 100
#define MaxInt 32767

typedef char VerTexType;
typedef int ArcType;

/**
 * 邻接矩阵的bfs代码
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
            G.arcs[i][j] = 0;
        }
    }
    // 构造邻接矩阵
    for (int k = 0; k < G.arcnum;k++) {
        cout << "请输入每条边所依附的顶点：" << endl;
        char v1, v2;
        int w = 1; //一条边所依附的顶点和权值
        cin >> v1 >> v2;
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        G.arcs[i][j] = w;
        G.arcs[j][i] = w;
    }
}

/**
 * 打印输出图
 */
void Display(AMGraph &G) {
    for (int i = 0; i < G.vexnum;i++) {
        for (int j = 0; j < G.vexnum;j++) {
            cout << G.arcs[i][j] << " ";
        }
        cout << endl;
    }
}




//----邻接矩阵的BFS遍历----

bool visited[MVNum]; 

void BFS_AM(AMGraph G, int v)
{//按广度优先非递归遍历连通图G
    cout<<v;
    visited[v] = true; //访问第v个顶点，并置访问标志数组相应分量值为true
    queue<int> Q;
    Q.push(v);
    while(!Q.empty())
    {
        int u = Q.front(); //队头元素出队并置为u
        Q.pop();
        for(int w = 0; w < G.vexnum; w++)
            if((G.arcs[u][w] != 0) && (!visited[w])) //G.arcs[v][w] != 0表示w是v的邻接点，!visited[w]表示未访问到                                            //w为u的尚未访问的邻接顶点
            {
                cout<<w;
                visited[w] = true; //访问w，并置访问标志数组相应分量值为true
                Q.push(w); //w进队
            }
    }
}

void BFSTraverse(AMGraph &G) {
    //访问标志数组初始化
    for(int v = 0; v < G.vexnum; v++)  
        visited[v] = false;
    //循环调用BFS
    for(int v = 0; v < G.vexnum; v++)  
        if(!visited[v])
            BFS_AM(G, v); //对尚未访问的顶点调用BFS
}


int main() {
    AMGraph test;
    CreateUDN(test);
    Display(test);
    // DFSTraverse(test);
    BFSTraverse(test);
    return 0;
}
