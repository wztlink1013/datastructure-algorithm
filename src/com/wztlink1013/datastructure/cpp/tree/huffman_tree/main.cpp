#include <bits/stdc++.h>
using namespace std;

int n, m, s1, s2;
typedef struct HTNode
{
    int weight, parent, lchild, rchild, pos;
    bool operator<(const HTNode &a)const
   {
       return a.weight < weight;
   }
}HTNode, *HuffmanTree;

priority_queue<HTNode>P;

void Select(HuffmanTree &HT, int ii, int &s1, int &s2)
{
    HTNode t = P.top();
    s1 = t.pos;
    P.pop();
    t = P.top();
    s2 = t.pos;
    P.pop();
}

void CreateHuffmantree(HuffmanTree &HT, int n)
{
    if(n <= 1)
        return;
    m = 2 * n - 1;
    HT = new HTNode[m + 1];
    for(int i = 1; i <= m; i++)
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    for(int i = 1; i <= n; ++i)
    {
        cin >> HT[i].weight;
        HT[i].pos = i;
        P.push(HT[i]);
    }
    for(int i = n + 1; i <= m; i++)
    {
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
        HT[i].pos = i ;
        P.push(HT[i]);
    }
}

int main()
{
    HuffmanTree HT;
    cout << "请输入哈夫曼树的叶子结点个数：";
    cin >> n;
    cout << "请输入每个叶子结点的权值：" << '\n';
    CreateHuffmantree(HT, n);
    for(int i = 1; i <= 2 * n - 1; ++i)
    {
        cout << "结点序号 " << i << " 权重 " << HT[i].weight
        << " parent " << HT[i].parent << " lchild " << HT[i].lchild
        << " rchild " << HT[i].rchild << '\n';
    }
}
