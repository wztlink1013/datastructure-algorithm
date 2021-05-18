#include <bits/stdc++.h>
using namespace std;

#define MVNum 100
#define MaxInt 32767

typedef char VerTexType;
typedef int OtherInfo;

/**
 * 邻接表的bfs代码
 */

/**
 * 存储结构
 */
typedef struct ArcNode {  //边结点                    
    int adjvex;  //该边所指向的结点的位置
    struct ArcNode *nextarc; //指向下一条边的指针
    OtherInfo info;   //和边相关的其他信息
}ArcNode;

typedef struct VNode {   //顶点信息
    VerTexType data;  //数据域，存放顶点vi的名称或其他有关信息
    ArcNode *firstarc;  //指向第一条依附该顶点的边的指针
}VNode, AdjList[MVNum]; //AdjList表示邻接表的类型

typedef struct {
    AdjList vertices;
    int vexnum, arcnum; //图当前的顶点数和边数
}ALGragh; //邻接表（Adjacency List）


/**
 * 找到v顶点在图的顶点数组中的位置
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
    cout << "请输入顶点数和边数：" << endl;
    cin >> G.vexnum >> G.arcnum; // 邻接表的顶点数和边数
    // 初始化顶点数组
    for (int i = 0; i < G.vexnum;i++) {
        cin >> G.vertices[i].data; // 初始化顶点数组里面的结点data
        G.vertices[i].firstarc = NULL; // 初始化顶点数组里面的结点next域
    }
    // 初始化所有的边
    for (int k = 0; k < G.arcnum;k++) {
        char v1, v2;
        cout << "请输入每条边所依附的顶点：" << endl;
        cin >> v1 >> v2;
        int i = LocateVex(G, v1); // 找到v1在顶点数组的下标
        int j = LocateVex(G, v2); // 找到v2在顶点数组的下标
        // 下面建立p1和p2是因为无向图，如果是有向图就没必要了只需要p1
        // 前插
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

/**
 * 打印输出图
 */
void Display(ALGragh &G) {
    for (int i = 0; i < G.vexnum;i++) {
        cout << "结点" << i << "：";
        // 复制选中的节点数组中的结点
        VNode p;
        p = G.vertices[i];
        if (p.firstarc != NULL){
            ArcNode *temp;
            temp = G.vertices[i].firstarc;
            while (temp != NULL) {
                cout << temp->adjvex<<" ";
                temp = temp->nextarc;
            }
            cout << "\n";
        }
    }
}



//----邻接表的BFS遍历----

bool visited[MVNum];

void BFS_AL(ALGragh &G, int v)
{//按广度优先非递归遍历连通图G
    cout<<v;
    visited[v] = true;    //访问第v个顶点，并置访问标志数组相应分量值为true
    ArcNode *p;    
    queue<int> Q;
    Q.push(v);
    while(!Q.empty()) {
        int u = Q.front();  //队头元素出队并置为u
        Q.pop();
        p = G.vertices[u].firstarc;   //p指向v的边链表的第一个边结点
        while(p != NULL){
            int w = p->adjvex;   //w是v的邻接点
            if(!visited[w])   //如果w未访问
                Q.push(w);
            p = p->nextarc;  //p指向下一个结点
        }
    }
}

void BFSTraverse(ALGragh &G) {
    //访问标志数组初始化
    for(int v = 0; v < G.vexnum; v++)  
        visited[v] = false;
    //循环调用BFS
    for(int v = 0; v < G.vexnum; v++)  
        if(!visited[v])
            BFS_AL(G, v); //对尚未访问的顶点调用BFS
}

int main() {
    ALGragh test;
    CreateUDG(test);
    // Display(test);
    BFSTraverse(test);
}