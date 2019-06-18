#include<stdio.h>
#include<vector>
#include<queue>
#define sz 1005
using namespace std;
int   vis[sz],cst[sz],i,j,k,u,v,l,t,node,edge,s;
vector<int>vec[sz];

void bfs()
{
    int i,j,u,v,l;
    queue<int>q;
    q.push(s);
    cst[s]=0;
    while(q.empty()==0)
    {
        u=q.front();
        q.pop();
        l=vec[u].size();
        for(j=0; j<l; j++)
        {
            v=vec[u][j];
            if(vis[v]==0)
            {
                q.push(v);
                vis[v]=1;
                cst[v]=cst[u]+1;
            }
        }
    }
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&node,&edge);
        while(edge--)
        {
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        for(i=0;i<node;i++)
        {
            vis[i]=0;
        }
        s=0;
        bfs();
        for(i=1;i<node;i++)
        {
            printf("%d\n",cst[i]);
        }
        if(t)
        {
            printf("\n");
        }
        for(i=0;i<node;i++)
        {
            vec[i].clear();
        }
    }
    return 0;
}
