#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<string>
#define sz 705
using namespace std;
vector<int>vec[sz];
map<string,int>mp;
int vis[sz],cst[sz],p[sz],i,j,k,t,u,v,l,node,source,dest,indx;
char c1[5],c2[5],ch[sz][5],re[sz][5];

void bfs()
{
    int i,j,u,v,l;
   queue<int>q;
   q.push(source);
   cst[source]=0;
   while(q.empty()==0)
   {
       u=q.front();
       q.pop();
       l=vec[u].size();
       for(i=0;i<l;i++)
       {
            v=vec[u][i];
            if(vis[v]==0)
            {
                q.push(v);
                vis[v]=1;
                cst[v]=cst[u]+1;
                p[v]=u;
            }
       }
   }
}
void save(int x)
{
    if(x==source)
    {
        strcpy(re[indx],ch[source]);
        indx++;
        return;
    }
    save(p[x]);
    strcpy(re[indx],ch[x]);
    indx++;
}
int main()
{
    int fg=1;
    while(scanf("%d",&t)==1)
    {
        if(!fg)
            printf("\n");
        fg=0;
        node=1;
        while(t--)
        {
            scanf("%s%s",c1,c2);
            if(mp[c1]==0)
            {
                mp[c1]=node++;
                strcpy(ch[node-1],c1);
            }
            if(mp[c2]==0)
            {
                mp[c2]=node++;
                strcpy(ch[node-1],c2);
            }
            u=mp[c1];
            v=mp[c2];
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        for(i=0;i<node;i++)
        {
            vis[i]=0;
        }
        scanf("%s%s",c1,c2);
        source=mp[c1];
        dest=mp[c2];
        bfs();
        if(vis[dest]==0)
        {
            printf("No route\n");
        }
        else
        {
            indx=1;
            save(dest);
            for(i=1;i<indx-1;i++)
            {
                printf("%s %s\n",re[i],re[i+1]);
            }
        }
        for(i=0;i<node;i++)
        {
            vec[i].clear();
        }
        mp.clear();
    }
    return 0;
}
