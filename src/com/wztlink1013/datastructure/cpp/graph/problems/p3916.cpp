#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+5;
int maxx[maxn],head[maxn],next[maxn],to[maxn];
int n,m,x,y,total;

void add(int u,int v){ 
	next[++total]=head[u];
	head[u]=total;
	to[total]=v;
}

void dfs(int u,int v)
{
	if(maxx[u])
		return;
	maxx[u]=v;
	for(register int e=head[u];e;e=next[e]){
		if(!maxx[to[e]])
			dfs(to[e],v);
	}
 }

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		add(y,x);//添加反向边 
	}
	for(int i=n;i;i--)//倒序深度遍历 
		dfs(i,i);
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
			cout<<" ";
		cout<<maxx[i];
	}
	return 0;
}
