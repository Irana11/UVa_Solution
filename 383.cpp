#include<stdio.h>
#include<queue>
#include<vector>
#include<map>
#include<string>
#define sz 35
using namespace std;
int cst[sz],vis[sz],i,j,k,l,u,v,source,dest,node,m,n,p,t,c;
char c1[5],c2[5];
map<string,int>mp;
vector<int>vec[sz];

void bfs()
{
    queue<int>q;
    int i,j,l,u,v;
    cst[source]=0;
    q.push(source);
    vis[source]=1;
    while(q.empty()==0)
    {
        u=q.front();
        q.pop();
        l=vec[u].size();
        for(j=0;j<l;j++)
        {
            v=vec[u][j];
            if(vis[v]==0)
            {
                cst[v]=cst[u]+1;
                vis[v]=1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int cs;
    printf("SHIPPING ROUTES OUTPUT\n\n");
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        node=1;
        scanf("%d%d%d",&m,&n,&p);
        while(m--)
        {
            scanf("%s",c1);
            mp[c1]=node++;
        }
        while(n--)
        {
            scanf("%s%s",c1,c2);
            u=mp[c1];
            v=mp[c2];
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
         printf("DATA SET  %d\n\n",cs);
        for(k=0;k<p;k++)
        {
            for(i=0;i<node;i++)
            vis[i]=0;
            scanf("%d",&c);
            scanf("%s%s",c1,c2);
            source=mp[c1];
            dest=mp[c2];
            bfs();
            if(vis[dest]==0)
            {
                printf("NO SHIPMENT POSSIBLE\n");
            }
            else
            {
                printf("$%d\n",cst[dest]*c*100);
            }
        }
        printf("\n");
        for(i=0;i<node;i++)
        {
            vec[i].clear();
        }
        mp.clear();
        if(cs==t)
        {
            printf("END OF OUTPUT\n");
        }
    }
    return 0;
}
